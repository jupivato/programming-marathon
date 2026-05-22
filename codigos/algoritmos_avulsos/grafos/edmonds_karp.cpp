#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Edmonds-Karp (Ford-Fulkerson com BFS) para fluxo maximo
// Parametros: n = numero de vertices, cap[u][v] = capacidade u->v, source, sink
// Retorna: valor do fluxo maximo de source ate sink

long long bfs(int source, int sink, vector<int>& parent, const vector<vector<long long>>& cap) {
    int n = cap.size();
    fill(parent.begin(), parent.end(), -1);
    parent[source] = source;
    
    queue<pair<int, long long>> q;
    q.push({source, INF});
    
    while (!q.empty()) {
        auto [u, flow] = q.front();
        q.pop();
        
        for (int v = 0; v < n; v++) {
            if (parent[v] == -1 && cap[u][v] > 0) {
                parent[v] = u;
                long long new_flow = min(flow, cap[u][v]);
                
                if (v == sink) {
                    return new_flow;
                }
                
                q.push({v, new_flow});
            }
        }
    }
    
    return 0;
}

long long max_flow(int n, int source, int sink, vector<vector<long long>> cap) {
    long long flow = 0;
    vector<int> parent(n);
    long long new_flow;
    
    while ((new_flow = bfs(source, sink, parent, cap)) > 0) {
        flow += new_flow;
        
        int v = sink;
        while (v != source) {
            int u = parent[v];
            cap[u][v] -= new_flow;
            cap[v][u] += new_flow;
            v = u;
        }
    }
    
    return flow;
}
