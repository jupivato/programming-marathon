#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Prim para encontrar arvore geradora minima
// Parametros: 
//   - n = numero de vertices
//   - adj = lista adjacencia onde adj[u] = {(vizinho, peso), ...}
// Retorna: peso total da MST
long long prim(int n, const vector<vector<pair<int, long long>>>& adj) {
    vector<bool> visited(n, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
    long long total_weight = 0;
    pq.push({0, 0}); // começa pelo vertice 0 com peso 0
    
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        
        if (visited[u]) continue; // ja foi adicionada
        
        visited[u] = true; // adiciona u a arvore
        total_weight += w;
        
        // explora todas as arestas de u nao visitadas
        for (auto [v, weight] : adj[u]) {
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }
    
    return total_weight;
}
