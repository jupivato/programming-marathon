#include <bits/stdc++.h>
using namespace std;

// P(n) = n!
long long fatorial(int n) {
    long long r = 1;
    for (int i = 2; i <= n; i++) r *= i;
    return r;
}

// A(n,k) = n! / (n-k)!
long long arranjo(int n, int k) {
    return fatorial(n) / fatorial(n - k);
}

// C(n,k) = n! / (k! * (n-k)!) - iterativo
long long combinacao(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;
    long long c = 1;
    for (int i = 0; i < k; i++)
        c = c * (n - i) / (i + 1);
    return c;
}

// Stifel: C(n,k) = C(n-1,k) + C(n-1,k-1)
long long comb_pascal(int n, int k, vector<vector<long long>>& dp) {
    if (k == 0 || k == n) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = comb_pascal(n - 1, k, dp) + comb_pascal(n - 1, k - 1, dp);
}

// Vandermonde: C(m+n,r) = sum_k C(m,k)*C(n,r-k)
long long vandermonde(int m, int n, int r) {
    long long s = 0;
    for (int k = 0; k <= r; k++)
        s += combinacao(m, k) * combinacao(n, r - k);
    return s;
}

// C_n = (1/(n+1)) * C(2n,n)
long long catalan(int n) {
    return combinacao(2 * n, n) / (n + 1);
}

// Stars and bars: solucoes de x1+...+xk=n, xi>=0
long long stars_and_bars(int n, int k) {
    return combinacao(n + k - 1, k - 1);
}

// Casa dos pombos: alguma caixa com pelo menos ceil(n/m) objetos
int pombos_min_por_caixa(int n, int m) {
    return (n + m - 1) / m; // ceil(n/m)
}

// PIE (exemplo): quantos x in [1..n] sao multiplos de a OU de b
int pie_multiplos(int n, int a, int b) {
    auto cnt = [&](int d) { return n / d; };
    int g = __gcd(a, b);
    return cnt(a) + cnt(b) - cnt(a / g * b);
}
