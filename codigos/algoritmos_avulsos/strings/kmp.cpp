#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

// Retorna as posicoes em que padrao aparece no texto.
vector<int> kmp(const string& texto, const string& padrao) {
    vector<int> pi = prefix_function(padrao);
    vector<int> match;
    for (int i = 0, j = 0; i < (int)texto.size(); i++) {
        while (j > 0 && texto[i] != padrao[j]) {
            j = pi[j - 1];
        }
        if (texto[i] == padrao[j]) {
            j++;
        }
        if (j == (int)padrao.size()) {
            match.push_back(i - j + 1);
            j = pi[j - 1]; // Continua buscando ocorrencias sobrepostas.
        }
    }
    return match;
}
