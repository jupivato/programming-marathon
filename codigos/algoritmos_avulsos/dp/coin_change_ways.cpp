#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Numero de maneiras de formar quantia x (moedas distinguiveis por ordem do loop)
long long coinChangeWays(int x, const vector<int>& coins) {
    vector<long long> ways(x + 1, 0);
    ways[0] = 1;
    for (int c : coins) {
        for (int i = c; i <= x; i++)
            ways[i] = (ways[i] + ways[i - c]) % MOD;
    }
    return ways[x];
}

// Ordem: for i, for c => combinações ORDENADAS por valor de moeda (cada moeda uma vez por i)
// Se precisar conjuntos nao ordenados: for c, for i (como mochila ilimitada de contagem)
