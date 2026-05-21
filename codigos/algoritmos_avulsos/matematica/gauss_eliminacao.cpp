#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
using matrix = vector<vector<double>>;

// --- Motor da Eliminação Gaussiana com Pivoteamento Parcial ---
// Transforma a matriz ’mat’ em sua forma escalonada ( triangular superior).
// Retorna o número de trocas de linha realizadas.int gaussian_elimination_engine (matrix& mat) {
    int n = mat.size ();
    int swaps = 0;
    for (int i = 0; i <n; i++) {
        int max_row = i;
        for (int k = i + 1; k <n; k++) {
            if (abs(mat[k][i]) > abs(mat[max_row ][i])) {
                max_row = k;
            }
        }
        if (i != max_row) {
            swap(mat[i], mat[max_row ]);
            swaps ++;
        }

        if (abs(mat[i][i]) <EPS) continue; // Matriz singular , mas continuamos

        for (int k = i + 1; k <n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j <mat [0].size (); j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }
    return swaps;
}

// --- Aplicação 1: Calculando o Determinante ---
double determinant(matrix mat) {
    if (mat.size () != mat [0].size ()) return 0; // Não é matriz quadrada
    int n = mat.size ();
    int swaps = gaussian_elimination_engine (mat);

    double det = 1.0;
    for (int i = 0; i <n; i++) {
        det *= mat[i][i];
    }

    return (swaps % 2 == 1) ? -det : det;
}

// --- Aplicação 2: Encontrando a Matriz Inversa ---
// Retorna a matriz inversa ou uma matriz vazia se não for invertível.matrix inverse_matrix (matrix mat) {
    if (mat.size () != mat [0].size ()) return {}; // Não é matriz quadrada
    int n = mat.size ();

    // Cria a matriz aumentada [A | I]
    matrix augmented(n, vector<double >(2 * n));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) augmented[i][j] = mat[i][j];
        augmented[i][i+n] = 1;
    }

    gaussian_elimination_engine (augmented);

    if (abs(augmented[n -1][n -1]) <EPS) return {}; // Não é invertível

    // Fase de eliminação para zerar a parte de CIMA da diagonal (Gauss -Jordan)
    for (int i = n - 1; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
            double factor = augmented[k][i] / augmented[i][i];
            for (int j = i; j <2 * n; j++) {
                augmented[k][j] -= factor * augmented[i][j];
            }
        }
    }

    // Transforma a parte esquerda em identidade e extrai a inversa
    matrix inv(n, vector<double >(n));
    for (int i = 0; i <n; i++) {
        double divisor = augmented[i][i];
        for (int j = 0; j <n; j++) {
            inv[i][j] = augmented[i][j + n] / divisor;
        }
    }
    return inv;
}

// --- Aplicação 3: Resolvendo Sistemas (como na versão anterior) ---
// O código da versão anterior para resolver sistemas continua válido.
// A função ‘eliminacao_gaussiana ‘ que montamos já faz o trabalho completo.vector<double > solve_system(matrix mat) {
    int n = mat.size ();
    gaussian_elimination_engine (mat);

    // Verificar se há solução (última linha não pode ser [0 ... 0 | c!=0])
    if (abs(mat[n -1][n -1]) <EPS && abs(mat[n -1][n]) > EPS) return {}; // Sem solução

    // Verificar se há infinitas soluções (última linha é [0 ... 0 | 0])
    // Este caso é mais complexo , aqui retornamos apenas o caso de solução única.if (abs(mat[n -1][n -1]) <EPS && abs(mat[n -1][n]) <EPS) return {}; // Infinitas soluções ( simplificado )

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
