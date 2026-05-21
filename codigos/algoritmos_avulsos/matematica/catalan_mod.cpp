#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005; // Precisa ser 2*N pois a formula pede (2n)!

long long fat[MAXN], inv_fat[MAXN ];

// Pre -calculo de fatoriais e inversos modulares em O(N log MOD )
// Rode essa funcao UMA VEZ na main ()
void pre_computar () {
    fat [0] = 1;
    inv_fat [0] = 1;
    for (int i = 1; i <MAXN; i++) {
        fat[i] = (fat[i - 1] * i) % MOD;
    }
    // Assumindo que voce tem a sua funcao mod_inv_prime (a, m) do notebook
    inv_fat[MAXN - 1] = mod_inv_prime (fat[MAXN - 1], MOD);
    for (int i = MAXN - 2; i >= 1; i--) {
        inv_fat[i] = (inv_fat[i + 1] * (i + 1)) % MOD;
    }
}

// Calcula C_n = (2n)! / (n! * (n+1)!) % MOD em O(1)
long long catalan_modular (int n) {
    if (n <0) return 0;
    long long num = fat[2 * n];
    long long den = (inv_fat[n] * inv_fat[n + 1]) % MOD;
    return (num * den) % MOD;
}
