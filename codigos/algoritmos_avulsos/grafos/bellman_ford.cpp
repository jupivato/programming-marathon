#include <bits/stdc++.h>

using namespace std;

// Defina o número máximo de vértices e um valor seguro para infinito.const int MAXN = 101;
const long long INF = 1e18;

// Estrutura para representar as arestas do grafo.
// Para o Bellman -Ford , uma lista de arestas é a forma mais fá cil de trabalhar.struct Aresta {
    int u, v; // Vértices de origem e destino
    long long peso;
};

int n; // Número de vértices
vector<long long > dist(MAXN , INF);

// Algoritmo de Bellman -Ford
// Parâmetros: s (origem), arestas (vetor com todas as arestas do grafo)
// Retorna: true se NÃO houver ciclo negativo , false se houver.
// O vetor ’dist ’ é preenchido com as menores distâncias.bool bellman_ford (int s, const vector<Aresta >& arestas) {
    // 1.Inicializa as distâncias
    dist.assign(n, INF);
    dist[s] = 0;

    // 2.Relaxa todas as arestas V-1 vezes
    for (int i = 0; i <n - 1; ++i) {
        for (const auto& aresta : arestas) {
            if (dist[aresta.u] != INF && dist[aresta.u] + aresta.peso <dist[aresta.v]) {
                dist[aresta.v] = dist[aresta.u] + aresta.peso;
            }
        }
    }

    // 3.V-ésima iteração para detectar ciclos de peso negativo
    for (const auto& aresta : arestas) {
        if (dist[aresta.u] != INF && dist[aresta.u] + aresta.peso <dist[aresta.v]) {
            // Se uma distância puder ser melhorada , há um ciclo negativo.return false;
        }
    }

    return true; // Nenhum ciclo negativo encontrado
}

// Exemplo de uso
int main () {
    int m; // Número de arestas
    cin>> n>> m;

    vector<Aresta > arestas(m);
    for (int i = 0; i <m; ++i) {
        cin>> arestas[i].u>> arestas[i].v>> arestas[i].peso;
    }

    int origem = 0;
    bool sem_ciclo_negativo = bellman_ford (origem , arestas);

    if (! sem_ciclo_negativo ) {
        cout <<"O grafo contem um ciclo de peso negativo!" <<endl;
    } else {
        cout <<"Distancias a partir da origem " <<origem <<" :" <<endl;
        for (int i = 0; i <n; ++i) {
            if (dist[i] == INF) {
                cout <<"Vertice " <<i <<": Nao alcancavel" <<endl;
            } else {
                cout <<"Vertice " <<i <<": " <<dist[i] <<endl;
            }
        }
    }

    return 0;
}
