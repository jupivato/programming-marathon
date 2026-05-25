#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXW = 1001;

int peso[MAXN], valor[MAXN];
vector<int> item_escolhido;

int knapsack_irrestrito(int W, int n) {
    vector<int> dp(W + 1, 0);
    item_escolhido.assign(W + 1, -1);

    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (peso[i] <= w) {
                if (dp[w] < dp[w - peso[i]] + valor[i]) {
                    dp[w] = dp[w - peso[i]] + valor[i];
                    item_escolhido[w] = i;
                }
            }
        }
    }
    return dp[W];
}

map<int, int> reconstruir_itens_irrestrito(int W) {
    map<int, int> itens;
    int w_atual = W;
    while (w_atual > 0 && item_escolhido[w_atual] != -1) {
        int item_idx = item_escolhido[w_atual];
        itens[item_idx]++;
        w_atual -= peso[item_idx];
    }
    return itens;
}
