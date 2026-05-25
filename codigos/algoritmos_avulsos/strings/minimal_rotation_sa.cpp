#include <bits/stdc++.h>
using namespace std;

// Suffix array (doubling) - O(n log n)
vector<int> suffix_array(const string &s) {
    int n = s.size();
    vector<int> sa(n), r(n), tmp(n);
    for (int i = 0; i < n; ++i) sa[i] = i, r[i] = (unsigned char)s[i];
    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (r[a] != r[b]) return r[a] < r[b];
            int ra = a + k < n ? r[a + k] : -1;
            int rb = b + k < n ? r[b + k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i) tmp[sa[i]] = tmp[sa[i-1]] + cmp(sa[i-1], sa[i]);
        r = tmp;
    }
    return sa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int n = s.size();
    string S = s + s;
    auto sa = suffix_array(S);
    for (int idx : sa) {
        if (idx < n) {
            cout << S.substr(idx, n) << '\n';
            return 0;
        }
    }
    return 0;
}
