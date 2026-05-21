#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5};

    sort(v.begin(), v.end());                    // crescente
    sort(v.rbegin(), v.rend());                  // decrescente
    reverse(v.begin(), v.end());

    // Remover duplicatas após sort (tamanho novo = it - begin)
    v = {1, 2, 2, 3};
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // Busca binária: vetor PRECISA estar ordenado
    sort(v.begin(), v.end());
    bool achou = binary_search(v.begin(), v.end(), 2);
    auto it = lower_bound(v.begin(), v.end(), 2);  // primeiro >= 2
    auto jt = upper_bound(v.begin(), v.end(), 2);  // primeiro > 2
    int qtd2 = jt - it;                              // quantos 2 existem

    // min / max em 2 ou 3 argumentos; min_element em intervalo
    int a = 1, b = 2;
    cout << min(a, b) << " " << max({a, b, 3}) << "\n";
    cout << *min_element(v.begin(), v.end()) << "\n";

    // gcd (C++17) e lcm manual
    int g = gcd(12, 18);
    int l = 12 / g * 18;

    // Soma de intervalo e preenchimento
    int soma = accumulate(v.begin(), v.end(), 0);
    fill(v.begin(), v.end(), 0);

    // next_permutation: próxima permutação lexicográfica
    string s = "abc";
    do {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
    cout << "\n";

    return 0;
}
