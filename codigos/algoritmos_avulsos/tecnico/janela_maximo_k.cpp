#include <bits/stdc++.h>
using namespace std;

// Para cada janela de tamanho k, retorna o maximo - O(n)
// deque guarda indices em ordem decrescente de valor
vector<int> slidingWindowMaximum(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    if (k <= 0 || n < k) return result;

    deque<int> dq; // indices

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}
