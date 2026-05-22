#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Floyd-Warshall para encontrar menores caminhos entre TODOS os pares
// Parametros: n = vertices, dist = matriz de adjacencia 
// Modifica dist in-place com as distancias minimas
void floyd_warshall(int n, vector<vector<long long>>& dist) {
    // itera cada vertice k como intermediario
    for (int k = 0; k < n; k++) {
        // verifica se caminho via k melhora qualquer outro caminho
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
