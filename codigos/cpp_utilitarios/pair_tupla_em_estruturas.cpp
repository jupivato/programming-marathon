#include <bits/stdc++.h>
using namespace std;

int main() {
    // --- SET com pair: ordena por .first, depois .second ---
    set<pair<int, int>> coords;
    coords.insert({2, 5});
    coords.insert({1, 9});
    coords.insert({2, 1});
    // percorre: (1,9), (2,1), (2,5)

    // SET com tuple: mesma ideia lexicografica (get<0>, get<1>, ...)
    set<tuple<int, int, int>> estados;
    estados.insert(make_tuple(1, 0, 5));
    estados.insert(make_tuple(0, 1, 3));
    estados.insert(make_tuple(1, 0, 2));
    // (0,1,3) vem antes de (1,0,2) porque get<0> menor

    // SET com comparador customizado em pair (ex.: ordenar so por .second)
    auto cmpSeg = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    };
    set<pair<int, int>, decltype(cmpSeg)> porY(cmpSeg);
    porY.insert({10, 3});
    porY.insert({5, 1});

    // --- MAP: chave pode ser pair ou tuple ---
    map<pair<int, int>, int> dist;
    dist[{0, 0}] = 0;
    dist[{1, 0}] = 1;
    dist[{0, 1}] = 1;
    for (auto& [cel, d] : dist)  // cel e pair, d e int
        cout << cel.first << "," << cel.second << " -> " << d << "\n";

    map<tuple<int, int, int>, string> memo;
    memo[{0, 0, 0}] = "origem";
    memo[make_tuple(1, 2, 3)] = "estado";

    // --- MULTISET de pair (ex.: multiset de intervalos (fim, inicio)) ---
    multiset<pair<int, int>> intervalos;
    intervalos.insert({10, 1});
    intervalos.insert({5, 2});
    intervalos.insert({10, 3});
    // varios (10, ...) coexistem; ordenados por .first

    // --- PRIORITY_QUEUE com pair (Dijkstra) ---
    // greater -> min-heap no .first (menor distancia no topo)
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    pq.push({5, 0});   // {distancia, vertice}
    pq.push({2, 3});
    pq.push({5, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        cout << "processa vertice " << u << " com dist " << d << "\n";
    }

    // --- PRIORITY_QUEUE com tuple (3 campos: dist, vertice, prioridade) ---
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>> pq3;
    pq3.push(make_tuple(7, 2, 0));
    pq3.push(make_tuple(3, 5, 1));
    int d = get<0>(pq3.top());
    int u = get<1>(pq3.top());

    // --- VECTOR de pair (arestas, eventos) ja visto no sort ---
    vector<pair<int, int>> arestas = {{1, 2}, {3, 4}, {1, 5}};
    sort(arestas.begin(), arestas.end());

    // --- VECTOR de vector de pair (grafo ponderado) ---
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);  // adj[u] = lista (vizinho, peso)
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 5});
    for (auto [v, peso] : adj[0])
        cout << "0 -> " << v << " peso " << peso << "\n";

    // --- SET de pair em map de componentes (exemplo) ---
    map<int, set<pair<int, int>>> grupos;
    grupos[1].insert({0, 0});
    grupos[1].insert({0, 1});

    return 0;
}
