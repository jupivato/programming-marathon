#include <bits/stdc++.h>
using namespace std;

// Encontra pontes (arestas cuja remocao desconecta o grafo)
// Parametros: n = numero de vertices, adj[] = lista adjacencia com {vizinho, id_aresta}
// Retorna: conjunto de IDs das arestas que sao pontes

vector<int> tin, low;
vector<bool> visited;
set<int> bridges;
int timer_val = 0;

void dfs_bridges(int u, int parent_edge_id, const vector<vector<pair<int, int>>>& adj) {
    visited[u] = true;
    tin[u] = low[u] = timer_val++;
    
    for (auto [v, edge_id] : adj[u]) {
        if (edge_id == parent_edge_id) continue; // ignora aresta de volta
        
        if (visited[v]) {
            low[u] = min(low[u], tin[v]); // back edge
        } else {
            dfs_bridges(v, edge_id, adj);
            low[u] = min(low[u], low[v]);
            
            // se low[v] > tin[u], entao v nao consegue voltar sem usar aresta u-v
            if (low[v] > tin[u]) {
                bridges.insert(edge_id);
            }
        }
    }
}

set<int> find_bridges(int n, const vector<vector<pair<int, int>>>& adj) {
    tin.assign(n, -1);
    low.assign(n, -1);
    visited.assign(n, false);
    bridges.clear();
    timer_val = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_bridges(i, -1, adj);
        }
    }
    
    return bridges;
}
