#include <bits/stdc++.h>
using namespace std;

// Fenwick tree (BIT) para soma prefixo
// Parametros: init_fenwick(n), add(idx, delta) com idx 0-based
// Retorna: sum_prefix(idx) = soma [0..idx], range_sum(l, r)
vector<long long> bit;

void init_fenwick(int n) {
    bit.assign(n + 1, 0); // 1-based interno
}

void add(int idx, long long delta) {
    for (int i = idx + 1; i < (int)bit.size(); i += i & -i) {
        bit[i] += delta;
    }
}

long long sum_prefix(int idx) {
    long long res = 0;
    for (int i = idx + 1; i > 0; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

long long range_sum(int l, int r) {
    if (l > r) return 0;
    return sum_prefix(r) - (l > 0 ? sum_prefix(l - 1) : 0);
}
