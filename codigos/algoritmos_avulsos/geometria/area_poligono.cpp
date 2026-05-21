#include <bits/stdc++.h>
using namespace std;

// --- Funções para Polígonos ---

// Typedef para facilitar a leitura (já deve estar no seu template)
using polygon = vector<point >;

// Calcula a área de um polígono simples (convexo ou côncavo)
// usando a Fórmula de Shoelace.Os vértices devem estar ordenados.
// Complexidade : O(N)
double area_poligono (const polygon& poly) {
    double area_duplicada = 0.0;
    int n = poly.size ();

    // Um polígono precisa de pelo menos 3 vértices para ter á rea.if (n <3) return

    // Itera por todos os vértices e soma os produtos vetoriais
    // de vértices adjacentes (poly[i] e poly[i+1]).for (int i = 0; i <n; i++) {
        area_duplicada += poly[i] % poly [(i + 1) % n];
    }

    // O resultado é a metade do valor absoluto da soma.return fabs( area_duplicada ) / 2.0;
}
