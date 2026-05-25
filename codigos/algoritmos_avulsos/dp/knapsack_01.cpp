#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXW = 1001;

int peso[MAXN], valor[MAXN];
int dp[MAXN][MAXW];

int knapsack_01_matriz(int W, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (peso[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w],
                               dp[i - 1][w - peso[i - 1]] + valor[i - 1]);
            }
        }
    }
    return dp[n][W];
}

vector<int> reconstruir_itens(int W, int n) {
    vector<int> itens_escolhidos;
    int w_atual = W;
    for (int i = n; i > 0 && w_atual > 0; --i) {
        if (dp[i][w_atual] != dp[i - 1][w_atual]) {
            itens_escolhidos.push_back(i - 1);
            w_atual -= peso[i - 1];
        }
    }
    return itens_escolhidos;
}
