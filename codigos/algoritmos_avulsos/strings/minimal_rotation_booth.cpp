#include <bits/stdc++.h>
using namespace std;

// Booth's algorithm: encontra o índice da menor rotação lexicográfica de s
int booth(const string &s) {
    string S = s + s;
    int n = s.size();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        if (S[i + k] == S[j + k]) { ++k; continue; }
        if (S[i + k] > S[j + k]) i = i + k + 1;
        else j = j + k + 1;
        if (i == j) ++i;
        k = 0;
    }
    return min(i, j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    if (s.empty()) { cout << "" << '\n'; return 0; }

    int idx = booth(s);
    // imprime a rotação mínima
    string res = s.substr(idx) + s.substr(0, idx);
    cout << res << '\n';
    return 0;
}
