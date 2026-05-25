#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];
long long peso[MAXN];
long long dpPega[MAXN], dpNaoPega[MAXN];

// Casa ladrão em árvore: em cada nó, pega o valor ou não pega (filhos não podem ser pegos se pai foi pego)
void dfsArvore(int v, int pai) {
    dpPega[v] = peso[v];
    dpNaoPega[v] = 0;

    for (int u : tree[v]) {
        if (u == pai) continue;
        dfsArvore(u, v);
        dpPega[v] += dpNaoPega[u];
        dpNaoPega[v] += max(dpPega[u], dpNaoPega[u]);
    }
}

long long maxPesoArvore(int raiz, int /*n*/) {
    dfsArvore(raiz, -1);
    return max(dpPega[raiz], dpNaoPega[raiz]);
}
