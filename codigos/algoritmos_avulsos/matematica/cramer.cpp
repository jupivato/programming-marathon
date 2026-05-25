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
            for (int j = col; j < n; j++) A[row][j] -= factor * A[col][j];
        }
    }
    return det;
}

vector<double> cramer(Matrix A, vector<double> b) {
    int n = (int)A.size();
    double det_a = determinant(A);
    if (fabs(det_a) < EPS) return {};

    vector<double> x(n);
    for (int col = 0; col < n; col++) {
        Matrix cur = A;
        for (int row = 0; row < n; row++) cur[row][col] = b[row];
        x[col] = determinant(cur) / det_a;
    }
    return x;
}
