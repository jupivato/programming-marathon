#include <bits/stdc++.h>
using namespace std;

// Sliding Window Maximum - O(n)
// Parametros: arr = vetor, k = tamanho da janela
// Retorna: vetor com o maximo de cada janela consecutiva
vector<int> sliding_window_max(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    if (k <= 0 || n == 0 || k > n) return result;

    deque<int> dq; // guarda indices, com valores em ordem decrescente
    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}
