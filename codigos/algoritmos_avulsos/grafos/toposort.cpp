#include <bits/stdc++.h>
using namespace std;

// Ordenacao topologica por DFS
// state: 0 nao visitado, 1 visitando, 2 visitado
// Precisa passar por referencia para manter estado entre recursoes
bool dfs(int u, vector<int> adj[], vector<int>& state, vector<int>& ordem) {
    state[u] = 1; // marca como visitando
    
    for (int v : adj[u]) {
        if (state[v] == 1) return false; // voltou para um vertice visitando = ciclo
        if (state[v] == 0 && !dfs(v, adj, state, ordem)) return false;
    }
    
    state[u] = 2; // marca como visitado
    ordem.push_back(u); // adiciona ao final da ordem
    return true;
}

// Funcao wrapper: chama isso na primeira vez
// Parametros: n = numero de vertices, adj[] = lista de adjacencia
// Retorna: vetor com vertices em ordem topologica, ou vazio se houver ciclo
vector<int> toposort(int n, vector<int> adj[]) {
    vector<int> state(n, 0); // cria array de estados
    vector<int> ordem;
    
    for (int u = 0; u < n; ++u) {
        if (state[u] == 0 && !dfs(u, adj, state, ordem)) return {}; // ciclo encontrado
    }
    
    reverse(ordem.begin(), ordem.end()); // inverte para ordem topologica correta
    return ordem;
}