#include <bits/stdc++.h>  

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visitado) {
    visitado[u] = true;
    for (int v : adj[u])
        if (!visitado[v]) 
          dfs(v, adj, visitado);
}

bool verificar_conectividade(int n, vector<vector<int>>& adj, vector<vector<int>>& adj_inv) 
{
    vector<bool> visitado(n + 1, false);
    vector<bool> visitado_inv(n + 1, false);
    
    dfs(1, adj, visitado);
    for (int i = 1; i <= n; i++) if (!visitado[i]) return false;

    dfs(1, adj_inv, visitado_inv);
    for (int i = 1; i <= n; i++) if (!visitado_inv[i]) return false;
    
    return true;
}

int main() 
{
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) 
    {
        vector<vector<int>> adj(n + 1);
        vector<vector<int>> adj_inv(n + 1);

        for (int i = 0; i < m; i++) 
        {
            int v, w, p;
            cin >> v >> w >> p;
            
            adj[v].push_back(w);
            adj_inv[w].push_back(v);
            
            if (p == 2) 
            {
                adj[w].push_back(v);
                adj_inv[v].push_back(w);
            }
        }

        if (verificar_conectividade(n, adj, adj_inv)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
