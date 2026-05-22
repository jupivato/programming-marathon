#include <bits/stdc++.h>
using namespace std;

// Sparse Table para RMQ (minimo) em array estatico
// Parametros: arr = vetor de valores (nao muda), st e log2 sao preenchidos
// Retorna: st e log2 prontos para consultas O(1)
void build_sparse_table(const vector<long long>& arr, vector<vector<long long>>& st, vector<int>& log2) {
    int n = arr.size();
    log2.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) log2[i] = log2[i / 2] + 1;

    int k = n > 0 ? log2[n] + 1 : 0;
    st.assign(k, vector<long long>(n));
    if (n == 0) return;

    st[0] = arr;
    for (int j = 1; j < k; ++j) {
        int len = 1 << j;
        for (int i = 0; i + len <= n; ++i) {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (len >> 1)]);
        }
    }
}

// Consulta de minimo no intervalo [l, r] (0-based, inclusivo)
long long range_min_query(const vector<vector<long long>>& st, const vector<int>& log2, int l, int r) {
    int len = r - l + 1;
    int j = log2[len];
    return min(st[j][l], st[j][r - (1 << j) + 1]);
}
