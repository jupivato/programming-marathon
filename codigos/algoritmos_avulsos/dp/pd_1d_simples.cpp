#include <bits/stdc++.h>
using namespace std;

// PD 1D: dp[i] depende de poucos indices anteriores
// Exemplo: subir escada (passos 1 ou 2)
int formasEscada(int n) {
    if (n <= 1) return 1;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return (int)dp[n];
}

// Mesma ideia com O(1) de memoria (so guarda os dois ultimos)
int formasEscadaO1(int n) {
    if (n <= 1) return 1;
    int a = 1, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}
