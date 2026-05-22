#include <bits/stdc++.h>
using namespace std;

// Tarjan para encontrar componentes fortemente conexos
// Parametros: n = numero de vertices, adj[] = lista adjacencia
// Retorna: vetor onde componente[i] = ID do SCC contendo vertice i

vector<int> dis, low, st;
vector<bool> in_stack;
int timer_val = 0;
int scc_count = 0;

void dfs_tarjan(int u, const vector<vector<int>>& adj, vector<int>& component) {
    dis[u] = low[u] = timer_val++;
    st.push_back(u);
    in_stack[u] = true;
    
    for (int v : adj[u]) {
        if (dis[v] == -1) {
            dfs_tarjan(v, adj, component);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dis[v]); // back edge
        }
    }
    
    // se u eh raiz de SCC, desempilha todo o componente
    if (low[u] == dis[u]) {
        while (true) {
            int v = st.back();
            st.pop_back();
            in_stack[v] = false;
            component[v] = scc_count;
            if (v == u) break;
        }
        scc_count++;
    }
}

void find_sccs(int n, const vector<vector<int>>& adj, vector<int>& component) {
    dis.assign(n, -1);
    low.assign(n, -1);
    in_stack.assign(n, false);
    component.assign(n, -1);
    timer_val = 0;
    scc_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (dis[i] == -1) {
            dfs_tarjan(i, adj, component);
        }
    }
}
