#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

// Recebe matriz aumentada A com n linhas e n+1 colunas.
// Retorna vetor vazio quando nao ha solucao unica.
vector<double> solve_linear_system(vector<vector<double>> A) {
    int n = (int)A.size();

    for (int col = 0; col < n; col++) {
        int pivot = col;
        for (int row = col + 1; row < n; row++) {
            if (fabs(A[row][col]) > fabs(A[pivot][col])) pivot = row;
        }
        swap(A[col], A[pivot]);
        if (fabs(A[col][col]) < EPS) return {};

        for (int row = col + 1; row < n; row++) {
            double factor = A[row][col] / A[col][col];
            for (int j = col; j <= n; j++) {
                A[row][j] -= factor * A[col][j];
            }
        }
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double rhs = A[i][n];
        for (int j = i + 1; j < n; j++) rhs -= A[i][j] * x[j];
        x[i] = rhs / A[i][i];
    }
    return x;
}
