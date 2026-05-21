#include <bits/stdc++.h>
using namespace std;

// mdc(a,b) - Euclides
int mdc(int a, int b) {
    while (b) { int t = a % b; a = b; b = t; }
    return a;
}

// mmc(a,b) = a*b / mdc(a,b)
long long mmc(int a, int b) {
    return 1LL * a * b / mdc(a, b);
}

// a equiv b (mod m)
bool congruente(long long a, long long b, long long m) {
    return (a - b) % m == 0;
}

// (a + b) mod m, (a * b) mod m
long long add_mod(long long a, long long b, long long m) {
    return (a % m + b % m) % m;
}
long long mul_mod(long long a, long long b, long long m) {
    return (a % m * b % m) % m;
}

// a^b mod m - exponenciacao rapida (Fermat/Euler)
long long binpow(long long a, long long b, long long m) {
    long long r = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}

// Inverso modular: a^(p-2) mod p (p primo)
long long inverso_mod_primo(long long a, long long p) {
    return binpow(a, p - 2, p);
}

// totiente(n) pelo produto sobre primos distintos
int totiente(int n) {
    int res = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            res -= res / p;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

// CRT: dois modulos coprimos m1, m2
long long crt2(long long a1, long long m1, long long a2, long long m2) {
    long long t = ((a2 - a1) % m2 + m2) % m2 * inverso_mod_primo(m1 % m2, m2) % m2;
    return (a1 + m1 * t) % (m1 * m2);
}

// Crivo de Eratostenes
vector<bool> crivo(int n) {
    vector<bool> primo(n + 1, true);
    primo[0] = primo[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (primo[i])
            for (int j = i * i; j <= n; j += i)
                primo[j] = false;
    return primo;
}
