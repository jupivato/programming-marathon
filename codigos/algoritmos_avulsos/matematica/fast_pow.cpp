#include <bits/stdc++.h>
using namespace std;

long long fast_pow(long long a, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1LL) res *= a;
        a *= a;
        e >>= 1LL;
    }
    return res;
}

long long mod_pow(long long a, long long e, long long mod) {
    long long res = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1LL) res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1LL;
    }
    return res;
}
