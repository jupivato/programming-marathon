#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5};

    // sort reorganiza o PROPRIO vetor (crescente por padrao)
    sort(v.begin(), v.end());
    // agora v = {1, 1, 3, 4, 5}

    // decrescente: reverse OU sort com greater
    sort(v.begin(), v.end(), greater<int>());

    // Ordenar SO um pedaco: do indice 1 ate antes do 4
    vector<int> w = {9, 8, 7, 6, 5};
    sort(w.begin() + 1, w.begin() + 4);

    // --- pair: compara .first; se empatar, compara .second ---
    vector<pair<int, int>> p = {{3, 1}, {1, 5}, {3, 0}};
    sort(p.begin(), p.end());
    // ordem: (1,5), (3,0), (3,1)

    // Ordenar par pelo SEGUNDO campo (lambda)
    sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    // Tirar duplicatas CONSECUTIVAS (precisa estar ordenado antes!)
    vector<int> u = {1, 1, 2, 2, 3};
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    // u = {1, 2, 3}

    return 0;
}
