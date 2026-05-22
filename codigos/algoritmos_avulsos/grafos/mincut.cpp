#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Min-Cut usando fluxo maximo (Teorema de Max-Flow Min-Cut)
// Parametros: n = vertices, cap[][] = capacidades, source, sink
// Retorna: capacidade do corte minimo (igual ao fluxo maximo)
// Os vertices reachaveis de source no grafo residual formam um lado do corte

vector<vector<long long>> cap;
vector<int> parent;

long long bfs(int source, int sink, int n) {
    parent.assign(n, -1);
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
                
                if (v == sink) return new_flow;
                
                q.push({v, new_flow});
            }
        }
    }
    
    return 0;
}

long long min_cut(int n, int source, int sink) {
    long long flow = 0;
    long long new_flow;
    
    while ((new_flow = bfs(source, sink, n)) > 0) {
        flow += new_flow;
        
        int v = sink;
        while (v != source) {
            int u = parent[v];
            cap[u][v] -= new_flow;
            cap[v][u] += new_flow;
            v = u;
        }
    }
    
    return flow; // capacidade do corte minimo
}
