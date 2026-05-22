#include <bits/stdc++.h>
using namespace std;

// Union-Find (DSU) - Disjoint Set Union
// Mandar: n = numero de elementos, link[] e sz[] são gerenciados aqui

vector<int> link, sz;

// inicializa union-find para n elementos
void init_uf(int n) {
    link.assign(n, 0);
    sz.assign(n, 1);
    iota(link.begin(), link.end(), 0); // link[i] = i
}

// encontra representante do conjunto contendo x com compressao de caminho
int find(int x) {
    if (x != link[x]) link[x] = find(link[x]);
    return link[x];
}

// une dois conjuntos, retorna true se foram unidos (false se já estavam)
bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false; // ja estao no mesmo conjunto
    
    // une por tamanho: coloca o menor sob o maior
    if (sz[a] < sz[b]) swap(a, b);
    link[b] = a;
    sz[a] += sz[b];
    return true;
}

// verifica se dois elementos estao no mesmo conjunto
bool same(int a, int b) {
    return find(a) == find(b);
}
