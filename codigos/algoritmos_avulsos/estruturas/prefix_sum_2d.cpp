#include <bits/stdc++.h>
using namespace std;

// Soma de prefixo 2D para consultas de submatriz
// Parametros: grid = matriz n x m (0-based)
// Retorna: matriz de prefixos (n+1 x m+1), 1-based para facilitar as contas
vector<vector<long long>> build_prefix_2d(const vector<vector<long long>>& grid) {
    int n = grid.size();
    int m = n ? (int)grid[0].size() : 0;
    vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }
    return pref;
}

// Soma no retangulo [x1..x2] x [y1..y2], com indices 0-based inclusivos
long long range_sum_2d(const vector<vector<long long>>& pref, int x1, int y1, int x2, int y2) {
    x1++;
    y1++;
    x2++;
    y2++;
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}
