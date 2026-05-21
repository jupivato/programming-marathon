#include <bits/stdc++.h>
using namespace std;

// PA: a_n = a1 + (n-1)*r
long long termo_pa(long long a1, long long r, int n) {
    return a1 + (n - 1) * r;
}

// S_n = (a1 + a_n) * n / 2
long long soma_pa(long long a1, long long r, int n) {
    long long an = termo_pa(a1, r, n);
    return (a1 + an) * n / 2;
}

long long potencia_inteira(long long q, int n) {
    long long r = 1;
    for (int i = 0; i < n; i++) r *= q;
    return r;
}

// PG: S_n = a1 * (q^n - 1) / (q - 1), q != 1
long long soma_pg(long long a1, long long q, int n) {
    if (q == 1) return a1 * n;
    return a1 * (potencia_inteira(q, n) - 1) / (q - 1);
}

// sum i = n(n+1)/2
long long soma_1_ate_n(int n) {
    return 1LL * n * (n + 1) / 2;
}

// sum i^2 = n(n+1)(2n+1)/6
long long soma_quadrados(int n) {
    return 1LL * n * (n + 1) * (2 * n + 1) / 6;
}

// sum i^3 = (n(n+1)/2)^2
long long soma_cubos(int n) {
    long long s = soma_1_ate_n(n);
    return s * s;
}

// sum_{i=0}^{n} 2^i = 2^{n+1} - 1
long long soma_potencias_2(int n) {
    return (1LL << (n + 1)) - 1;
}

// sum_{i=0}^{n} x^i = (x^{n+1}-1)/(x-1)
long long soma_geometrica(long long x, int n) {
    if (x == 1) return n + 1;
    return (potencia_inteira(x, n + 1) - 1) / (x - 1);
}
