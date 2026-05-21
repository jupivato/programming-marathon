#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001; // Máximo de itens
const int MAXW = 1001; // Capacidade máxima

int peso[MAXN], valor[MAXN ];
int dp[MAXN ][ MAXW ]; // Matriz de memoização

// Calcula o valor máximo para a Mochila 0/1
int knapsack_01_matriz (int W, int n) {
    // dp[i][w] = valor máximo usando os primeiros ’i’ itens com capacidade ’w’
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // Se o item atual não cabe na mochila , a única opç ão é não pegá-lo.if (peso[i-1] > w) {
                dp[i][w] = dp[i -1][w];
            } else {
                // Se o item cabe , temos duas opções:
                // 1.Não pegar o item: o valor é o mesmo de antes (dp[i -1][w])
                // 2.Pegar o item: o valor é dp[i -1][w-peso[i -1]] + valor[i-1]
                // Escolhemos a opção que der o maior valor.dp[i][w] = max(dp[i -1][w], dp[i -1][w - peso[i -1]] + valor[i -1]);
            }
        }
    }
    return dp[n][W];
}

// Reconstrói quais itens foram escolhidos a partir da matriz DP
vector<int > reconstruir_itens (int W, int n) {
    vector<int > itens_escolhidos ;
    int w_atual = W;
    for (int i = n; i > 0 && w_atual > 0; --i) {
        // Compara o resultado atual com o da linha anterior.
        // Se for diferente , significa que o item ’i’ foi essencial para
        // alcançar o valor em dp[i][ w_atual], então ele foi escolhido.if (dp[i][ w_atual] != dp[i -1][ w_atual ]) {
            itens_escolhidos .push_back(i - 1); // Adiciona o í ndice do item
            w_atual -= peso[i -1];
        }
    }
    return itens_escolhidos ;
} 2.Mochila Irrestrita (Unbounded Knapsack)
