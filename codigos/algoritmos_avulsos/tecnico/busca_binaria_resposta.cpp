#include <bits/stdc++.h>
using namespace std;

// Busca binaria na RESPOSTA (nao no indice do vetor).
// Requisito: existe um limiar L tal que ok(x) e falso para x < L e verdadeiro para x >= L
// (funcao monotona em x). Complexidade: O(log R * custo_de_ok), R = faixa da resposta.

// Exemplo: menor valor "capacidade" que permite dividir nums em <= k partes com soma <= cap
bool podeDividir(const vector<int>& nums, int k, long long cap) {
    int partes = 1;
    long long soma = 0;
    for (int x : nums) {
        if (x > cap) return false;
        if (soma + x > cap) {
            partes++;
            soma = x;
        } else {
            soma += x;
        }
    }
    return partes <= k;
}

// Menor x em [lo, hi] tal que ok(x) == true (primeiro verdadeiro)
long long primeiroVerdadeiro(long long lo, long long hi,
                             const function<bool(long long)>& ok) {
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// Maior x em [lo, hi] tal que ok(x) == true (ultimo verdadeiro)
long long ultimoVerdadeiro(long long lo, long long hi,
                           const function<bool(long long)>& ok) {
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if (ok(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

// Uso tipico: minimizar capacidade
long long menorCapacidade(const vector<int>& nums, int k) {
    long long lo = *max_element(nums.begin(), nums.end());
    long long hi = accumulate(nums.begin(), nums.end(), 0LL);
    auto ok = [&](long long cap) { return podeDividir(nums, k, cap); };
    return primeiroVerdadeiro(lo, hi, ok);
}

// Uso tipico: maximizar o minimo (ex.: distancia minima entre postos)
// bool ok(long long d) { ... retorna se da para colocar com distancia >= d ... }
// return ultimoVerdadeiro(lo, hi, ok);
