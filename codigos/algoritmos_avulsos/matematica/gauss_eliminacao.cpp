#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
using Matrix = vector<vector<double>>;

double determinant(Matrix A) {
    int n = (int)A.size();
    double det = 1.0;

    for (int col = 0; col < n; col++) {
        int pivot = col;
        for (int row = col + 1; row < n; row++) {
            if (fabs(A[row][col]) > fabs(A[pivot][col])) pivot = row;
        }
        if (fabs(A[pivot][col]) < EPS) return 0.0;
        if (pivot != col) {
            swap(A[pivot], A[col]);
            det = -det;
        }
        det *= A[col][col];

        for (int row = col + 1; row < n; row++) {
            double factor = A[row][col] / A[col][col];
            for (int j = col; j < n; j++) {
                A[row][j] -= factor * A[col][j];
            }
        }
    }
    return det;
}

Matrix inverse(Matrix A) {
    int n = (int)A.size();
    Matrix aug(n, vector<double>(2 * n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) aug[i][j] = A[i][j];
        aug[i][i + n] = 1.0;
    }

    for (int col = 0; col < n; col++) {
        int pivot = col;
        for (int row = col + 1; row < n; row++) {
            if (fabs(aug[row][col]) > fabs(aug[pivot][col])) pivot = row;
        }
        if (fabs(aug[pivot][col]) < EPS) return {};
        swap(aug[pivot], aug[col]);

        double div = aug[col][col];
        for (int j = 0; j < 2 * n; j++) aug[col][j] /= div;

        for (int row = 0; row < n; row++) {
            if (row == col) continue;
            double factor = aug[row][col];
            for (int j = 0; j < 2 * n; j++) {
                aug[row][j] -= factor * aug[col][j];
            }
        }
    }

    Matrix inv(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) inv[i][j] = aug[i][j + n];
    }
    return inv;
}
