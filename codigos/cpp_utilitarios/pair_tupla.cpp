#include <bits/stdc++.h>
using namespace std;

int main() {
    // pair: dois valores, ordenação lexicográfica no sort
    pair<int, int> p = {3, 1};
    p = make_pair(5, 2);
    cout << p.first << " " << p.second << "\n";

    vector<pair<int, int>> arestas;
    arestas.push_back({1, 2});
    sort(arestas.begin(), arestas.end());  // menor (u,v) primeiro

    // tupla: 3 ou mais campos; get<i> pega o i-ésimo (índice começa em 0)
    tuple<int, int, string> t = make_tuple(1, 2, "abc");
    cout << get<0>(t) << " " << get<2>(t) << "\n";

    // tie: desempacota pair/tupla em variáveis
    int a, b;
    tie(a, b) = p;

    // C++17: structured bindings
    auto [x, y] = p;
    auto [i, j, s] = t;

    // Comparar pares no map/set: ordena por first, depois second
    map<pair<int, int>, int> freq;
    freq[{1, 2}]++;

    return 0;
}
