#include <bits/stdc++.h>
using namespace std;

// Pré-requisito: Template Básico de Geometria 2D com a struct ’point ’ e ’ccw ’.
// A struct ’point ’ precisa ter o membro estático ’pivot ’.

// --- Fecho Convexo (Convex Hull) ---

// Função de comparação para a Ordenação Polar em sentido anti - horário.
// Usa o ’point :: pivot ’ global que deve ser definido antes de chamar std:: sort.bool cmp_polar(point a, point b) {
    // Usa ccw para determinar a ordem angular em relação ao pivô
    int order = ccw(point ::pivot , a, b);
    if (order == 0) { // Se forem colineares com o pivô...
        // ...o ponto mais próximo do pivô vem primeiro.return cmp(abs(a - point :: pivot), abs(b - point :: pivot) ) <0;
    }
    // Caso contrário , a ordem é definida pelo sentido anti -hor ário.return order > 0;
}

// Algoritmo de Graham Scan para encontrar o Fecho Convexo.
// Modifica o vetor ’pts’ para conter apenas os pontos do fecho em ordem anti -horária.void fecho_convexo (vector<point >& pts , bool include_collinear = false) {
    if (pts.size () <= 2) {
        return;
    }

    // 1.Encontrar o pivô (ponto mais baixo e à esquerda) e colocá-lo no início.int pivot_idx = 0;
    for (int i = 1; i <pts.size (); i++) {
        if (cmp(pts[i].y, pts[pivot_idx ].y) <0 ||
        (cmp(pts[i].y, pts[pivot_idx ].y) == 0 && cmp(pts[i].x, pts[pivot_idx ].x) <0)) {
            pivot_idx = i;
        }
    } de pontos colineares.swap(pts[0], pts[pivot_idx ]);
    point :: pivot = pts [0];

    // 2.Ordenar os pontos restantes pelo ângulo polar.sort(pts.begin () + 1, pts.end(), cmp_polar);

    // Opcional: Tratar pontos colineares no último segmento do fecho.
    // O sort já ordena os pontos colineares pela distância.Para o fecho , queremos o
    // mais distante por último , então revertemos o bloco final
    if ( include_collinear ) {
        int i = (int)pts.size () - 1;
        while (i > 0 && ccw(point ::pivot , pts[i], pts.back ()) == 0) i--;
        reverse(pts.begin () + i + 1, pts.end());
    }

    // 3.Construir o fecho.vector<point > hull;
    for (const auto& p : pts) {
        // Remove pontos da pilha enquanto a adição de ’p’ não formar uma "curva à esquerda ".
        // Uma curva à direita (ccw <0) ou uma linha reta (ccw == 0) indica que o
        // ponto anterior se tornou interno ao novo fecho.while (hull.size () > 1) {
            int decision = ccw(hull[hull.size () - 2], hull.back (), p);
            if (decision <0 || (decision == 0 && ! include_collinear )) {
                hull.pop_back ();
            } else {
                break;
            }
        }
        hull.push_back(p);
    }
    pts = hull;
}
