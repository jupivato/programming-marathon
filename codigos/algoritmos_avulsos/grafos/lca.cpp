#include <bits/stdc++.h>
using namespace std;

const int MAXN = 212345;
const int LOG = 20;

int depth[MAXN];
int parent[LOG][MAXN];
vector<int> adj[MAXN];

// Prepara arvore para LCA usando DFS
// Calcula profundidade e parent imediato
void dfs(int u, int p, int d) {
    parent[0][u] = p;
    depth[u] = d;
    
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

// Computa ancestors binarios (2^k jumps)
void preprocess_lca(int n) {
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i < n; i++) {
            if (parent[k-1][i] != -1) {
                parent[k][i] = parent[k-1][parent[k-1][i]];
            } else {
                parent[k][i] = -1;
            }
        }
    }
}

// Encontra o lowest common ancestor de u e v
int lca(int u, int v) {
    // deixa u mais profundo
    if (depth[u] < depth[v]) swap(u, v);
    
    // sobe u ate mesma profundidade de v
    int diff = depth[u] - depth[v];
    for (int k = 0; k < LOG; k++) {
        if ((diff >> k) & 1) {
            u = parent[k][u];
        }
    }
    
    if (u == v) return u;
    
    // sobe ambos ate encontrar LCA
    for (int k = LOG - 1; k >= 0; k--) {
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    
    return parent[0][u];
}
