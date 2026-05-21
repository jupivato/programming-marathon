#include <bits/stdc++.h>

using namespace std;

// Encontra todos os divisores de ’n’ em O(sqrt(n)).vector<long long > encontrar_divisores (long long n) {
    vector<long long > divisores;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisores.push_back(i);
            // Evita adicionar a raiz quadrada duas vezes se ’n ’ for um quadrado perfeito.if (i * i != n) {
                divisores.push_back(n / i);
            }
        }
    }
    // Opcional: ordena os divisores para uma saída mais limpa.sort(divisores.begin (), divisores.end());
    return divisores;
}
