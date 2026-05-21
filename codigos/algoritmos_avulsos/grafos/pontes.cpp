#include <bits/stdc++.h>
using namespace std;

long long n;
vector<vector<pair<long long, long long>>> adj;
vector<bool> visited;
vector<long long> tin, low;
long long timer;
map<pair<long long, long long>, long long> bridges;

void dfsBridges(long long v, long long edge_from_parent = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;

    for (auto t : adj[v]) {
        long long to = t.first;
        long long edge_id = t.second;
        if (edge_id == edge_from_parent) continue;

        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfsBridges(to, edge_id);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges[{min(v, to), max(v, to)}] = edge_id;
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    bridges.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfsBridges(i, -1);
    }
}
