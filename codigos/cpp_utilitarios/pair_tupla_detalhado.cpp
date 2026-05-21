#include <bits/stdc++.h>
using namespace std;

int main() {
    // PAIR: exatamente dois campos
    pair<int, char> p;
    p.first = 42;
    p.second = 'A';

    pair<int, int> e = make_pair(1, 2);
    pair<int, int> f = {3, 4};       // C++11: mesma coisa

    // Ordenacao automatica de pair<int,int>:
    // menor first; empate -> menor second
    vector<pair<int, int>> arestas = {{2, 5}, {1, 9}, {2, 1}};
    sort(arestas.begin(), arestas.end());
    // resultado: (1,9), (2,1), (2,5)

    // TUPLA: 3 ou mais campos (tipos podem ser diferentes)
    tuple<int, int, string> t = make_tuple(10, 20, "oi");
    int a = get<0>(t);               // 10
    string nome = get<2>(t);         // "oi"
    // get<1>(t) seria 20

    // Desempacotar sem get:
    int x, y;
    tie(x, y) = e;                   // x=3, y=4

    // C++17: nomes diretos
    auto [u, v] = e;

    // Map com chave pair
    map<pair<int, int>, int> vis;
    vis[{0, 0}] = 1;
    if (vis.count({0, 0}))
        cout << vis[{0, 0}] << "\n";

    return 0;
}
