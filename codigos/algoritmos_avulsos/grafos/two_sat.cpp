#include <bits/stdc++.h>
using namespace std;

// 2-SAT solver usando Kosaraju para SCCs
// Parametros: n = numero de variaveis, implicacoes = lista de implicacoes (x => y)
// Retorna: true se satisfazivel (com atribuicao em assignment[]), false caso contrario

vector<int> order;
vector<bool> visited;
vector<int> assignment;

void dfs1(int u, const vector<vector<int>>& graph) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) dfs1(v, graph);
    }
    order.push_back(u);
}

void dfs2(int u, int comp, const vector<vector<int>>& rev_graph, vector<int>& component) {
    visited[u] = true;
    component[u] = comp;
    for (int v : rev_graph[u]) {
        if (!visited[v]) dfs2(v, comp, rev_graph, component);
    }
}

bool solve_2sat(int n, const vector<vector<int>>& graph, const vector<vector<int>>& rev_graph) {
    visited.assign(2 * n, false);
    order.clear();
    
    // primeira DFS em grafo original
    for (int i = 0; i < 2 * n; i++) {
        if (!visited[i]) dfs1(i, graph);
    }
    
    // segunda DFS em grafo reverso
    vector<int> component(2 * n);
    visited.assign(2 * n, false);
    int comp_id = 0;
    reverse(order.begin(), order.end());
    for (int u : order) {
        if (!visited[u]) {
            dfs2(u, comp_id, rev_graph, component);
            comp_id++;
        }
    }
    
    // verifica se variaveis e negacoes estao em mesmo SCC
    assignment.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (component[2 * i] == component[2 * i + 1]) {
            return false; // insatisfazivel
        }
        // assignment[i] = 1 se (~i) tem SCC maior que i
        assignment[i] = component[2 * i + 1] > component[2 * i];
    }
    
    return true; // satisfazivel
}
