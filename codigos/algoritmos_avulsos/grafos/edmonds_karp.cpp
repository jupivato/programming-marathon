#include <bits/stdc++.h>
using namespace std;

// Edmonds -Karp - O(V * E^2)
const int MAX = 110; // Número máximo de vértices
const long long INF = 1e18;

int n; // Número de vértices
long long capacity[MAX][MAX];
vector<int > adj[MAX];

// Encontra um caminho de aumento usando BFS
long long bfs(int s, int t, vector<int >& parent) {
    fill(parent.begin (), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int , long long>> q;
    q.push ({s, INF});

    while (!q.empty ()) {
        int u = q.front ().first;
        long long flow = q.front ().second;
        q.pop();

        for (int v : adj[u]) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                long long new_flow = min(flow , capacity[u][v]);
                if (v == t) {
                    return new_flow;
                }
                q.push ({v, new_flow });
            }
        }
    }
    return 0; // Nenhum caminho de aumento encontrado
}

// Função principal do Edmonds -Karp
long long edmonds_karp(int s, int t) {
    long long max_flow = 0;
    vector<int > parent(n + 1);
    long long new_flow;

    // Enquanto houver um caminho de aumento
    while (( new_flow = bfs(s, t, parent)) > 0) {
        max_flow += new_flow;
        int current = t;
        while (current != s) {
            int prev = parent[current ];
            // Atualiza capacidades no grafo residual
            capacity[prev ][ current] -= new_flow;
            capacity[current ][ prev] += new_flow;
            current = prev;
        }
    }
    return max_flow;
}

// Para usar:
// 1.Defina ’n’ (número de vértices).
// 2.Preencha a matriz ’capacity ’ e a lista ’adj ’.
// Para arestas bidirecionais , adicione capacidade em ambos os sentidos.
// 3.Chame edmonds_karp(source , sink).
// 4.Lembre -se de limpar as estruturas (capacity , adj) para mú ltiplos casos de teste.
