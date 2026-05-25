#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> coins;

// Minimo numero de moedas para formar quantia x
int solve_troco(int x) {
    vector<int> value(x + 1, INF);
    value[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0 && value[i - c] != INF)
                value[i] = min(value[i], value[i - c] + 1);
        }
    }
    return value[x] == INF ? -1 : value[x];
}
