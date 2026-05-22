#include <bits/stdc++.h>
using namespace std;

struct Aresta {
    int u, v;
    long long peso;
};

const long long INF = 1e18;

// Bellman-Ford para encontrar menores caminhos com arestas negativas
// Detecta ciclo negativo se houver
// Parametros: n = vertices, start = origem, arestas = todas arestas
// Retorna: true sem ciclo negativo, false com ciclo negativo
bool bellman_ford(int n, int start, const vector<Aresta>& arestas, vector<long long>& dist) {
    dist.assign(n, INF);
    dist[start] = 0;
    
    // relaxa arestas n-1 vezes
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& a : arestas) {
            if (dist[a.u] != INF && dist[a.u] + a.peso < dist[a.v]) {
                dist[a.v] = dist[a.u] + a.peso;
            }
        }
    }
    
    // verifica ciclo negativo na n-esima iteracao
    for (const auto& a : arestas) {
        if (dist[a.u] != INF && dist[a.u] + a.peso < dist[a.v]) {
            return false; // ciclo negativo encontrado
        }
    }
    
    return true; // sem ciclo negativo
}
