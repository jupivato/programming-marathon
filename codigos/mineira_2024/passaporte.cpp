#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXK = 105;

vector<pair<int,int>> adj[MAXN];
int dist[MAXN][MAXK];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for(int i = 1; i <= N; i++)
        for(int j = 0; j <= K; j++)
            dist[i][j] = INT_MAX;

    queue<tuple<int,int,int>> q;

    dist[1][0] = 0;
    q.push({1, 0, 0});

    while(!q.empty()) {
        auto [u, cost, flights] = q.front();
        q.pop();

        for(auto [v, w] : adj[u]) {
            int new_cost = cost + w;

            if(new_cost > K) continue;

            if(dist[v][new_cost] > flights + 1) {
                dist[v][new_cost] = flights + 1;
                q.push({v, new_cost, flights + 1});
            }
        }
    }

    int ans = INT_MAX;
    for(int c = 0; c <= K; c++)
        ans = min(ans, dist[N][c]);

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}
