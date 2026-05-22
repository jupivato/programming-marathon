#include <bits/stdc++.h>
using namespace std;

struct Aresta {
    int u, v;
    long long peso;
    bool operator<(const Aresta& other) const {
        return peso < other.peso;
    }
};

// Union-Find global para Kruskal
vector<int> uf_link, uf_sz;

// inicializa union-find
void init_uf(int n) {
    uf_link.assign(n, 0);
    uf_sz.assign(n, 1);
    iota(uf_link.begin(), uf_link.end(), 0);
}

// encontra representante
int find(int x) {
    if (x != uf_link[x]) uf_link[x] = find(uf_link[x]);
    return uf_link[x];
}

// une conjuntos
bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (uf_sz[a] < uf_sz[b]) swap(a, b);
    uf_link[b] = a;
    uf_sz[a] += uf_sz[b];
    return true;
}

// Kruskal para encontrar arvore geradora minima
// Parametros: n = numero de vertices, arestas = vetor de todas as arestas {u, v, peso}
// Retorna: peso total da MST, ou -1 se grafo desconexo
long long kruskal(int n, vector<Aresta>& arestas) {
    sort(arestas.begin(), arestas.end()); // ordena por peso
    
    init_uf(n); // inicializa union-find
    long long total = 0;
    int arestas_adicionadas = 0;
    
    for (const auto& a : arestas) {
        if (unite(a.u, a.v)) { // se conseguiu unir (nao fecha ciclo)
            total += a.peso;
            arestas_adicionadas++;
        }
    }
    
    return (arestas_adicionadas == n - 1) ? total : -1; // -1 = desconexo
}
