#include <bits/stdc++.h>
using namespace std;

// Handshaking: sum deg(v) = 2|E|
bool verifica_handshaking(const vector<int>& grau) {
    long long soma = 0;
    for (int g : grau) soma += g;
    return soma % 2 == 0; // |E| = soma/2 e inteiro
}

int numero_arestas(const vector<int>& grau) {
    long long soma = 0;
    for (int g : grau) soma += g;
    return (int)(soma / 2);
}

// Euler planar: V - E + F = 2  =>  F = E - V + 2
int faces_euler(int V, int E) {
    return E - V + 2;
}

// Esperanca de indicadores: E[X] = sum P(X_i = 1)
// Exemplo: numero esperado de faces "6" em n dados
double esperanca_dados(int n) {
    return n * (1.0 / 6.0);
}

// Markov: P(X >= t) <= E[X]/t  (X >= 0)
bool markov_cota(double EX, double t, double prob_observada) {
    return prob_observada <= EX / t + 1e-9;
}
