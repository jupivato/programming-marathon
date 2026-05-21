#include <bits/stdc++.h>
using namespace std;

// Tamanho máximo do número (ex: 18 para long long)
const int MAX_DIGITS = 20;
const int MAX_SUM = 180; // Estado máximo (9 * 20 dígitos)

// dp[pos][ tight ][ leading_zeros ][ state]
// Geralmente inicializado com -1
long long dp[MAX_DIGITS ][2][2][ MAX_SUM ];
string str_N; // O número limite convertido para string
int target_sum; // Variável global de exemplo para o estado

long long solve(int pos , int tight , int lz , int current_sum) {
    // Caso base: chegamos no final do número
    if (pos == str_N.size ()) {
        // Aqui você coloca a condição de sucesso do seu problema
        return (current_sum == target_sum) ? 1 : 0;
    }

    // Retorna o valor memoizado , mas ATENÇÃO:
    // Só podemos reaproveitar estados que NÃO são tight.
    // Estados tight dependem de um prefixo específico e só acontecem uma vez.if (! tight && dp[pos][ tight ][lz][ current_sum] != -1) {
        return dp[pos][ tight ][lz][ current_sum ];
    }

    long long ans = 0;

    // Qual o maior dígito que podemos colocar nessa posição?
    int limit = tight ? (str_N[pos] - ’0’) : 9;

    for (int d = 0; d <= limit; d++) {
        // Atualiza a flag tight:
        // Continua tight se já era tight E colocamos o dígito limite.int new_tight = tight && (d == limit);

        // Atualiza a flag de leading zeros:
        // Continua sendo zero à esquerda se já era E colocamos o dígito 0.int new_lz = lz && (d == 0);

        // --- TRANSIÇÃO DE ESTADO ---
        // Aqui você atualiza o seu "state" dependendo da quest ão.int new_sum = current_sum;
        if (! new_lz || d > 0) {
            // Exemplo: só soma se não for um zero à esquerda ( útil para produtos , etc)
            // Neste caso simples de soma , zeros não fariam diferença, mas mantive a estrutura.new_sum += d;
        }

        ans += solve(pos + 1, new_tight , new_lz , new_sum);
    }

    // Salva na DP (apenas se não for tight)
    if (! tight) {
        dp[pos][ tight ][lz][ current_sum] = ans;
    }

    return ans;
}

// Função auxiliar que chama a DP para um número N
long long get_ans(long long N) {
    if (N <0) return 0;
    str_N = to_string(N);
    // Só precisamos limpar a DP uma vez (se os casos de teste compartilharem os mesmos limites/estados)
    // Se o problema muda as regras por query , limpe a DP toda vez.memset(dp , -1, sizeof(dp));

    // pos = 0, tight = 1 (sim , estamos no teto), lz = 1 (sim , só temos zeros por enquanto), state = 0
    return solve (0, 1, 1, 0);
}

// Resolve para o intervalo [A, B]
long long solve_range(long long A, long long B) {
    return get_ans(B) - get_ans(A - 1);
}

int main () {
    target_sum = 10;
    long long A = 10, B = 100;

    cout <<"Numeros entre " <<A <<" e " <<B
    <<" com soma dos digitos igual a " <<target_sum <<" : "
    <<solve_range(A, B) <<endl;

    return 0;
}
