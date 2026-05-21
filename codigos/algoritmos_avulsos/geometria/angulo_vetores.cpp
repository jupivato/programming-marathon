// Pré-requisito: Template Básico de Geometria 2D

// Calcula o ângulo PQR (com vértice em Q) em radianos.double angulo(point p, point q, point r) {
    // Cria os vetores a partir do vértice Q
    point u = p - q; // Vetor QP
    point v = r - q; // Vetor QR

    // Usa os operadores sobrecarregados :
    // u % v -> produto vetorial (cross product)
    // u * v -> produto escalar (dot product)
    return atan2(u % v, u * v);
}
// para graus: double graus = angulo_radianos * 180.0 / PI;
