#include <bits/stdc++.h>
using namespace std;

// Mochila 0/1 com um unico vetor dp[w] - O(n * W), O(W) memoria
// Loop em w DECRESCENTE para nao usar o mesmo item duas vezes
int knapsack_01_1d(int W, const vector<int>& peso, const vector<int>& valor) {
    int n = peso.size();
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= peso[i]; w--)
            dp[w] = max(dp[w], dp[w - peso[i]] + valor[i]);
    }
    return dp[W];
}
