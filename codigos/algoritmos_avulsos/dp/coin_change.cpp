#include <bits/stdc++.h>
using namespace std;

const int MAXX = 10001; // Quantia máxima
const int INF = 1e9;

// Vetor com os valores das moedas
vector<int > coins;

// Calcula o troco para ’x’ de forma iterativa (Bottom -Up)
int solve_troco(int x) {
    // value[i] = o número mínimo de moedas para formar a quantia i
    vector<int > value(x + 1, INF);

    // Caso base: 0 moedas para formar a quantia 0
    value [0] = 0;

    // Constrói a solução para cada quantia de 1 até x
    for (int i = 1; i <= x; i++) {
        // Tenta usar cada moeda para otimizar o resultado para a quantia ’i’
        for (int c : coins) {
            if (i - c >= 0 && value[i - c] != INF) {
                // A solução para ’i’ é o mínimo entre o valor atual e
                // (1 + a solução para o troco restante ’i-c ’)
                value[i] = min(value[i], value[i - c] + 1);
            }
        }
    }

    // Se o valor continuar INF , não é possível formar o troco.
    // Pode retornar -1 ou o próprio INF , dependendo do problema.return value[x] == INF ? -1 : value[x];
}

/*
// Exemplo de uso:
int main () {
    coins = {1, 3, 4};
    int x = 10;
    int resultado = solve_troco(x);
    if (resultado != -1) {
        cout <<"Minimo de moedas para " <<x <<": " <<resultado <<endl; // Saída: 3 (4+3+3)
    } else {
        cout <<"Nao eh possivel formar o troco para " <<x <<endl;
    }
    return 0;
}
*/
