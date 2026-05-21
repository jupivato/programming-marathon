#include <bits/stdc++.h>
using namespace std;

// Rabin -Karp - O(|s| + |t|)
vector<int > rabin_karp(const string& s, const string& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.length (), T = t.length ();

    // Pré-calcula potências de p
    vector<long long > p_pow(max(S, T));
    p_pow [0] = 1;
    for (int i = 1; i <p_pow.size (); i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    // Calcula hashes de todos os prefixos do texto ’t’
    vector<long long > h(T + 1, 0);
    for (int i = 0; i <T; i++) {
        h[i + 1] = (h[i] + (t[i] - ’a’ + 1) * p_pow[i]) % m;
    }

    // Calcula o hash do padrão ’s’
    long long h_s = 0;
    for (int i = 0; i <S; i++) {
        h_s = (h_s + (s[i] - ’a’ + 1) * p_pow[i]) % m;
    }

    vector<int > occurrences;
    for (int i = 0; i + S - 1 <T; i++) {
        // Calcula o hash da substring atual de ’t’
        long long cur_h = (h[i + S] - h[i] + m) % m;

        // Compara com o hash do padrão
        if (cur_h == (h_s * p_pow[i]) % m) {
            occurrences.push_back(i);
        }
    }
    return occurrences;
}
