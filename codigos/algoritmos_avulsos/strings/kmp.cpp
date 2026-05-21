#include <bits/stdc++.h>
using namespace std;

// KMP - Algoritmo Principal - O(|t|)
vector<int > kmp(const string& t, const string& s) {
    vector<int > pi = prefix_function (s);
    vector<int > match;
    for (int i = 0, j = 0; i <t.length (); i++) {
        while (j > 0 && t[i] != s[j]) {
            j = pi[j - 1];
        }
        if (t[i] == s[j]) {
            j++;
        }
        if (j == s.length ()) {
            match.push_back(i - j + 1);
            j = pi[j - 1]; // Continua a busca por mais ocorrê ncias
        }
    }
    return match;
}
