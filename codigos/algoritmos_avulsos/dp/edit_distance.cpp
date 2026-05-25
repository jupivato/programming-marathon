#include <bits/stdc++.h>
using namespace std;
// funcao que calcula a distancia de Levenshtein entre duas strings
int levenshtein_distance(const string& a, const string& b) {
    int n = a.size(); // tamanho da primeira string
    int m = b.size(); // tamanho da segunda string
    // criacao da matriz dp com (n+1) linhas e (m+1) colunas, inicializada com 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // inicializa a primeira coluna (transformar prefixo de a em string vazia)
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    // inicializa a primeira linha (transformar string vazia em prefixo de b)
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    // preenchimento da matriz dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                // se os caracteres sao iguais, nao ha custo
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // se diferentes, considerar a operacao de substituicao, insercao ou remocao
                dp[i][j] = min({
                    dp[i - 1][j - 1] + 1, // substituicao
                    dp[i][j - 1] + 1,          // insercao
                    dp[i - 1][j] + 1           // remocao
                });
            }
        }
    }
    // retorna a distancia de Levenshtein entre as duas strings
    return dp[n][m];
}
