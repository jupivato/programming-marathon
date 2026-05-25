#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (long long p = 2; p * p <= n; p++) {
        if (!is_prime[p]) continue;
        for (long long x = p * p; x <= n; x += p) {
            is_prime[x] = false;
        }
    }
    return is_prime;
}
