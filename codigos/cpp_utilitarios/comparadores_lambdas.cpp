#include <bits/stdc++.h>
using namespace std;

struct Evento {
    int t, id;
};

// Ordenar struct: função ou operador <
bool cmpEvento(const Evento& a, const Evento& b) {
    if (a.t != b.t) return a.t < b.t;
    return a.id < b.id;
}

int main() {
    vector<Evento> ev = {{5, 2}, {3, 1}, {5, 0}};
    sort(ev.begin(), ev.end(), cmpEvento);

    // Ordenar por segundo campo do pair (distância, vértice)
    vector<pair<int, int>> adj = {{10, 1}, {5, 2}, {5, 0}};
    sort(adj.begin(), adj.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    // set com comparador customizado (ex.: ordenar por .second)
    auto cmpSeg = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    };
    set<pair<int, int>, decltype(cmpSeg)> porSegundo(cmpSeg);

    // auto: deixa o compilador inferir o tipo
    auto x = 1e9 + 7;
    auto it = adj.begin();

    return 0;
}
