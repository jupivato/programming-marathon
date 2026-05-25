#include <bits/stdc++.h>
using namespace std;

// Duval's algorithm: decomposição em palavras de Lyndon
vector<string> duval(const string &s) {
    int n = s.size();
    vector<string> res;
    int i = 0;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j]) k = i;
            else ++k;
            ++j;
        }
        int l = j - k;
        while (i <= k) {
            res.push_back(s.substr(i, l));
            i += l;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    auto parts = duval(s);
    // imprime as fatores de Lyndon separados por espaço
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i) cout << ' ';
        cout << parts[i];
    }
    cout << '\n';
    return 0;
}
