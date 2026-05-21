#include <bits/stdc++.h>
using namespace std;

// --- Constantes e Globais ---
const int MAXN = 1001; // Máximo de itens
const int MAXW = 1001; // Capacidade máxima

int peso[MAXN], valor[MAXN ];

// Vetor auxiliar para guardar qual item foi escolhido para cada capacidade.
// É preenchido pela função principal e usado pela função de reconstrução.vector<int > item_escolhido ;


// --- Funções ---

// Calcula o valor máximo para a Mochila Irrestrita e prepara a reconstrução.int knapsack_irrestrito (int W, int n) {
    vector<int > dp(W + 1, 0);
    item_escolhido .assign(W + 1, -1);

    for (int w = 1; w <= W; w++) {
        for (int i = 0; i <n; i++) {
            if (peso[i] <= w) {
                if (dp[w] <dp[w - peso[i]] + valor[i]) {
                    dp[w] = dp[w - peso[i]] + valor[i];
                    item_escolhido [w] = i; // Guarda a melhor escolha para a capacidade ’w’
                }
            }
        }
    }
    return dp[W];
}

// Reconstrói os itens usados a partir do vetor ’item_escolhido ’.
// Retorna um map onde a chave é o índice do item e o valor é a quantidade.map<int , int > reconstruir_itens_irrestrito (int W) {
    map<int , int > itens;
    int w_atual = W;

    // Volta do final , pegando a melhor escolha para cada capacidade
    while (w_atual > 0 && item_escolhido [w_atual] != -1) {
        int item_idx = item_escolhido [w_atual ];
        itens[item_idx ]++;
        w_atual -= peso[item_idx ];
    }
    return itens;
}

/*
// --- Exemplo de como usar na main ---
int main () {
    int n, W;
    // ...ler n, W, e os vetores peso [] e valor [] ...

    // 1.Calcula o valor máximo e preenche o vetor ’ item_escolhido ’
    int max_valor = knapsack_irrestrito (W, n);

    // 2.Usa o vetor preenchido para descobrir os itens
    map<int , int > itens_usados = reconstruir_itens_irrestrito (W );

    cout <<"Valor maximo: " <<max_valor <<endl;
    cout <<"Itens usados (indice -> quantidade):" <<endl;
    for (auto const& [item , qtd] : itens_usados) {
        cout <<item <<" -> " <<qtd <<endl;
    }
    return 0;
}
*/
