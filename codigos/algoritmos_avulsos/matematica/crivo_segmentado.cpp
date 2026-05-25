#include <bits/stdc++.h>
using namespace std;

vector<long long> simple_primes(long long n) {
    vector<bool> is_prime(n + 1, true);
    vector<long long> primes;
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (long long i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        if (i * i <= n) {
            for (long long j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

vector<bool> segmented_sieve(long long L, long long R) {
    vector<bool> is_prime(R - L + 1, true);
    for (long long p : simple_primes(sqrt(R) + 1)) {
        long long start = max(p * p, ((L + p - 1) / p) * p);
        for (long long x = start; x <= R; x += p) {
            is_prime[x - L] = false;
        }
    }
    if (L == 0) is_prime[0] = false;
    if (L <= 1 && 1 <= R) is_prime[1 - L] = false;
    return is_prime;
}
