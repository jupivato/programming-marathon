#include <bits/stdc++.h>
using namespace std;

// Detecta ciclo em grafo dirigido usando DFS
// state: 0 nao visitado, 1 visitando, 2 visitado
// Precisa passar por referencia para manter estado entre recursoes
bool hascycle(int u, vector<int> adj[], vector<int>& state) {
    state[u] = 1; // marca como visitando
    
    for (int v : adj[u]) {
        if (state[v] == 1) return true; // voltou para um vertice visitando = ciclo
        if (state[v] == 0 && hascycle(v, adj, state)) return true;
    }
    
    state[u] = 2; // marca como visitado
    return false;
}

// Funcao wrapper: chama isso na primeira vez
// Parametros: n = numero de vertices, adj[] = lista de adjacencia
bool hascycle(int n, vector<int> adj[]) {
    vector<int> state(n, 0); // cria array de estados
    
    for (int u = 0; u < n; ++u) {
        if (state[u] == 0 && hascycle(u, adj, state)) return true;
    }
    return false;
}