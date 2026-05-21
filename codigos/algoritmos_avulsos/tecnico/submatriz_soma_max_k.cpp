#include <bits/stdc++.h>
using namespace std;
int maxSumSubmatrix(const vector<vector<int>>& mat, int k)
{
    if (mat.empty() || mat[0].empty()) {
        return 0;
    }
    int R = mat.size();
    int C = mat[0].size();
    if (k > R || k > C) {
        cout <<"Erro: O valor de k é maior que as dimensões da matriz." <<endl;
        return -1;
    }
    vector<vector<int>> stripSum(R, vector<int>(C));
    for (int j = 0; j <C; ++j) {
        int sum = 0;
        for (int i = 0; i <k; ++i) {
            sum += mat[i][j];
        }
        stripSum[k - 1][j] = sum;
        for (int i = k; i <R; ++i) {
            sum += mat[i][j] - mat[i - k][j];
            stripSum[i][j] = sum;
        }
    }
    int maxSum = INT_MIN;
    for (int i = k - 1; i <R; ++i) {
        int sum = 0;
        for (int j = 0; j <k; ++j) {
            sum += stripSum[i][j];
        }
        maxSum = max(maxSum, sum);
        for (int j = k; j <C; ++j) {
            sum += stripSum[i][j] - stripSum[i][j - k];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
} (inserção, remoção ou substituição de caracteres) necessárias para transformar uma string na outra.
