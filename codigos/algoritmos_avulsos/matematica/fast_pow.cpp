#include <bits/stdc++.h>

using namespace std;

// É crucial usar uma tolerância (EPS) para comparar doubles.const double EPS = 1e-9;

// Função para resolver um sistema de N equações lineares com N variáveis.
// Recebe a matriz aumentada mat[N][N+1].
// Retorna um vetor com a solução.Se não houver solução única , retorna um vetor vazio.vector<double > eliminacao_gaussiana (vector<vector<double>>& mat ) {
    int n = mat.size ();

    // --- Fase 1: Eliminação Progressiva com Pivoteamento Parcial ---
    for (int i = 0; i <n; i++) {
        // 1.Pivoteamento: Encontrar a linha com o maior pivô na coluna ’i’
        int max_row = i;
        for (int k = i + 1; k <n; k++) {
            if (abs(mat[k][i]) > abs(mat[max_row ][i])) {
                max_row = k;
            }
        }
        swap(mat[i], mat[max_row ]);

        // 2.Verificar se o sistema tem solução única.
        // Se o maior pivô for próximo de zero , a matriz é singular.if (abs(mat[i][i]) <EPS) {
            // Não há solução única (pode ter 0 ou infinitas soluções).return {};
        }

        // 3.Zerar os elementos abaixo do pivô na coluna ’i’
        for (int k = i + 1; k <n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j <n + 1; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // --- Fase 2: Substituição Reversa ---
    vector<double > sol(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j <n; j++) {
            sum += mat[i][j] * sol[j];
        }
        sol[i] = (mat[i][n] - sum) / mat[i][i];
    }

    return sol;
}

// Exemplo de uso
int main () {
    // Exemplo: Resolver o sistema
    // 2x + y - z = 8
    // -3x - y + 2z = -11
    // -2x + y + 2z = -3
    // Solução é x=2, y=3, z=-1

    int n = 3;
    // Matriz aumentada [A|b]
    vector<vector<double>> mat = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    vector<double > solucao = eliminacao_gaussiana (mat);

    if (solucao.empty ()) {
        cout <<"O sistema nao possui solucao unica." <<endl;
    } else {
        cout <<"Solucao:" <<endl;
        for (int i = 0; i <n; i++) {
            cout <<"x" <<i <<" = " <<solucao[i] <<endl;
        }
    }

    return 0;
}
