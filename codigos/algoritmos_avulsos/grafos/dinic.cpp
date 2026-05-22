#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to, rev;
    long long cap;
};

// Dinic para fluxo maximo (mais rapido que Edmonds-Karp)
// Parametros: n = numero de vertices, graph = lista adjacencia com capacidades
// Chamadas: add_edge(u, v, cap) para cada aresta, max_flow(source, sink)

vector<vector<Edge>> graph;
vector<int> level, iter;

void bfs(int s) {
    level.assign(graph.size(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& e : graph[v]) {
            if (level[e.to] < 0 && e.cap > 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

long long dfs(int v, int t, long long f) {
    if (v == t) return f;
    
    for (int& i = iter[v]; i < graph[v].size(); i++) {
        Edge& e = graph[v][i];
        if (level[v] < level[e.to] && e.cap > 0) {
            long long d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                graph[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

void add_edge(int from, int to, long long cap) {
    graph[from].push_back({to, (int)graph[to].size(), cap});
    graph[to].push_back({from, (int)graph[from].size() - 1, 0});
}

long long max_flow(int s, int t) {
    long long flow = 0;
    while (true) {
        bfs(s);
        if (level[t] < 0) return flow;
        iter.assign(graph.size(), 0);
        long long f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}
