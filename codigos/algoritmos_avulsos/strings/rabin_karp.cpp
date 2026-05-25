#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp - O(|padrao| + |texto|)
vector<int> rabin_karp(const string& padrao, const string& texto) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = (int)padrao.size(), T = (int)texto.size();

    // Pre-calcula potencias de p.
    vector<long long> p_pow(max(S, T));
    p_pow [0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    // Calcula hashes de todos os prefixos do texto.
    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++) {
        h[i + 1] = (h[i] + (texto[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Calcula o hash do padrao.
    long long h_s = 0;
    for (int i = 0; i < S; i++) {
        h_s = (h_s + (padrao[i] - 'a' + 1) * p_pow[i]) % m;
    }

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        // Calcula o hash da substring atual do texto.
        long long cur_h = (h[i + S] - h[i] + m) % m;

        // Compara com o hash do padrao.
        if (cur_h == (h_s * p_pow[i]) % m) {
            occurrences.push_back(i);
        }
    }
    return occurrences;
}
