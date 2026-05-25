#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long mod_pow(long long a, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1LL) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1LL;
    }
    return res;
}

struct CatalanMod {
    vector<long long> fact, inv_fact;

    CatalanMod(int max_n) {
        int n = 2 * max_n + 2;
        fact.assign(n + 1, 1);
        inv_fact.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        inv_fact[n] = mod_pow(fact[n], MOD - 2);
        for (int i = n; i > 0; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }

    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    }

    long long catalan(int n) {
        return comb(2 * n, n) * mod_pow(n + 1, MOD - 2) % MOD;
    }
};
