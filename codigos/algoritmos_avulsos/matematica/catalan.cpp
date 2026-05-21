#include <bits/stdc++.h>
using namespace std;

// Calcula o N-esimo Numero de Catalan em O(N)
// CUIDADO: Cresce absurdamente rapido.C_35 ja estoura o ’long long ’.long long catalan_simples (int n) {
    if (n <= 1) return 1;
    long long c = 1;
    for (int i = 0; i <n; i++) {
        c = c * 2 * (2 * i + 1) / (i + 2);
    }
    return c;
}
