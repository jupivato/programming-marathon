#include <bits/stdc++.h>

using namespace std;

// Defina o número máximo de vértices que o problema pode ter.const int MAXN = 101;
// Use um valor grande para infinito , mas que evite overflow na soma.const long long INF = 1e18;

int n; // Número de vértices
long long dist[MAXN ][ MAXN ];

// Função para inicializar a matriz de adjacência/distâncias
void inicializar_matriz () {
    for (int i = 0; i <n; i++) {
        for (int j = 0; j <n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
}

// Algoritmo de Floyd -Warshall
void floyd_warshall () {
    // Itera por cada vértice ’k’ como um possível intermediá rio
    for (int k = 0; k <n; k++) {
        // Itera por todas as origens ’i’
        for (int i = 0; i <n; i++) {
            // Itera por todos os destinos ’j’
            for (int j = 0; j <n; j++) {
                // Se k é um intermediário válido (caminhos não infinitos)
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    // Atualiza a distância se o caminho via ’k ’ for mais curto
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// Exemplo de uso
int main () {
    // Leitura do número de vértices (n) e arestas (m)
    int m;
    cin>> n>> m;

    inicializar_matriz ();

    // Leitura das arestas
    for (int i = 0; i <m; i++) {
        int u, v;
        long long peso;
        cin>> u>> v>> peso;
        // Para grafos com arestas múltiplas , é comum pegar a de menor peso
        dist[u][v] = min(dist[u][v], peso);
        // Se o grafo for não-direcionado , adicione a aresta de volta
        // dist[v][u] = min(dist[v][u], peso);
    }

    // Roda o algoritmo
    floyd_warshall ();

    // Agora , dist[i][j] contém a menor distância entre os vé rtices i e j.int origem = 0, destino = n - 1;
    if (dist[origem ][ destino] == INF) {
        cout <<"Nao ha caminho entre " <<origem <<" e " <<destino <<endl;
    } else {
        cout <<"A menor distancia entre " <<origem <<" e " <<destino <<" eh: " <<dist[origem ][ destino] <<endl;
    }

    // Detecção de ciclo negativo: após rodar o algoritmo , se dist[i][i] <0
    // para qualquer ’i’, então existe um ciclo negativo alcanç ável a partir de ’i ’.return 0;
}
