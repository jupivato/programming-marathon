#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;     // Um valor grande o suficiente para representar "infinito"
// Funcao de Dijkstra
// n: numero de vertices
// adj: lista de adjacencia (adj[u] = {{v1, custo1}, {v2, custo2}, ...})
// start: vertice de origem
// Retorna vetor de distancias minimas ate todos os vertices
vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int start) {
    vector<int> dist(n, INF);     // Inicializa todas as distancias com infinito
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});     // (custo, vertice)
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;     // Se for um caminho antigo, ignora
        for (auto [v, cost] : adj[u]) {
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;     // dist[i] eh o custo minimo de start ate i
}
int main() {
    int n = 5;     // numero de vertices
    vector<vector<pair<int, int>>> adj(n);       // grafo
    // adicionando arestas (u, v, custo)
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});
    // Entrada do usuário
    int origem, destino;
    cout <<"Digite o vertice de origem (0 a " <<n-1 <<"): ";
    cin>> origem;
    cout <<"Digite o vertice de destino (0 a " <<n-1 <<"): ";
    cin>> destino;
    vector<int> dist = dijkstra(n, adj, origem);
    if (dist[destino] == INF) {
        cout <<"Não existe caminho de " <<origem <<" ate " <<destino <<endl;
    } else {
        cout <<"Custo minimo de " <<origem <<" ate " <<destino <<": " <<dist[destino] <<endl;
    }
    return 0;
}
