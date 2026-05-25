#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

using Matrix = array<array<long long, 2>, 2>;

Matrix multiply(Matrix a, Matrix b) {
    Matrix c = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

Matrix matrix_pow(Matrix base, long long exp) {
    Matrix res = {{{1, 0}, {0, 1}}};
    while (exp > 0) {
        if (exp & 1LL) res = multiply(res, base);
        base = multiply(base, base);
        exp >>= 1LL;
    }
    return res;
}

long long fibonacci(long long n) {
    if (n == 0) return 0;
    Matrix base = {{{1, 1}, {1, 0}}};
    return matrix_pow(base, n)[0][1];
}
