#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long a, long long e, long long mod) {
    long long res = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1LL) res = res * a % mod;
        a = a * a % mod;
        e >>= 1LL;
    }
    return res;
}

// Valido quando mod eh primo e a nao eh multiplo de mod.
long long mod_inv_prime(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}
