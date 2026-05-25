#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using u128 = __uint128_t;

u64 mul_mod(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

u64 pow_mod(u64 a, u64 e, u64 mod) {
    u64 res = 1;
    while (e > 0) {
        if (e & 1ULL) res = mul_mod(res, a, mod);
        a = mul_mod(a, a, mod);
        e >>= 1ULL;
    }
    return res;
}

bool is_prime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        if (n % p == 0) return n == p;
    }

    u64 d = n - 1, s = 0;
    while ((d & 1ULL) == 0) {
        d >>= 1ULL;
        s++;
    }

    for (u64 a : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        if (a >= n) continue;
        u64 x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool witness = true;
        for (u64 r = 1; r < s; r++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                witness = false;
                break;
            }
        }
        if (witness) return false;
    }
    return true;
}

u64 pollard_rho(u64 n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;

    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (true) {
        u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
        u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
        u64 y = x;
        u64 d = 1;

        auto f = [&](u64 v) {
            return (mul_mod(v, v, n) + c) % n;
        };

        while (d == 1) {
            x = f(x);
            y = f(f(y));
            u64 diff = x > y ? x - y : y - x;
            d = gcd(diff, n);
        }
        if (d != n) return d;
    }
}

void factor(u64 n, map<u64, int>& factors) {
    if (n == 1) return;
    if (is_prime(n)) {
        factors[n]++;
        return;
    }
    u64 d = pollard_rho(n);
    factor(d, factors);
    factor(n / d, factors);
}
