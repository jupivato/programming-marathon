#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int n = s.size();
    string best = s;
    for (int i = 1; i < n; ++i) {
        string r = s.substr(i) + s.substr(0, i);
        if (r < best) best = r;
    }
    cout << best << '\n';
    return 0;
}
