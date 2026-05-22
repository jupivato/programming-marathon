#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Dijkstra para encontrar menores caminhos de um vertice para todos
// Parametros: n = vertices, adj = lista adjacencia com pares (vizinho, custo), start = origem
// Retorna: vetor com distancia minima de start para cada vertice
vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int start) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    dist[start] = 0;
    pq.push({0, start}); // (custo, vertice)
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue; // ignorar caminho antigo
        
        for (auto [v, cost] : adj[u]) {
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
    cin>> destino;
    vector<int> dist = dijkstra(n, adj, origem);
    if (dist[destino] == INF) {
        cout <<"Não existe caminho de " <<origem <<" ate " <<destino <<endl;
    } else {
        cout <<"Custo minimo de " <<origem <<" ate " <<destino <<": " <<dist[destino] <<endl;
    }
    return 0;
}
