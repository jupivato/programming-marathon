#include <bits/stdc++.h>
using namespace std;

// Kosaraju para encontrar componentes fortemente conexos
// Parametros: n = numero de vertices, adj[] = lista adjacencia
// Retorna: vetor onde componente[i] = ID do SCC contendo vertice i

vector<int> order;
vector<bool> visited;

void dfs1(int u, const vector<vector<int>>& adj) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v, adj);
    }
    order.push_back(u); // pos-order
}

void dfs2(int u, const vector<vector<int>>& adj_rev, int comp_id, vector<int>& component) {
    visited[u] = true;
    component[u] = comp_id;
    for (int v : adj_rev[u]) {
        if (!visited[v]) dfs2(v, adj_rev, comp_id, component);
    }
}

void find_sccs(int n, const vector<vector<int>>& adj, vector<int>& component) {
    visited.assign(n, false);
    order.clear();
    component.assign(n, -1);
    
    // primeira DFS para obter ordem de finalizacao
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs1(i, adj);
    }
    
    // cria grafo reverso
    vector<vector<int>> adj_rev(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            adj_rev[v].push_back(u);
        }
    }
    
    // segunda DFS em ordem reversa de finalizacao
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    int comp_id = 0;
    for (int u : order) {
        if (!visited[u]) {
            dfs2(u, adj_rev, comp_id, component);
            comp_id++;
        }
    }
}
