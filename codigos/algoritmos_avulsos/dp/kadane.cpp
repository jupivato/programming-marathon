#include <bits/stdc++.h>
using namespace std;

// Maior soma de subarray contiguo - O(n)
long long maxSubarraySum(const vector<int>& a) {
    long long best = LLONG_MIN;
    long long cur = 0;
    for (int x : a) {
        cur = max((long long)x, cur + x);
        best = max(best, cur);
    }
    return best;
}

// Variante: retorna tambem os indices [l, r] do melhor intervalo
tuple<long long, int, int> maxSubarraySumIndices(const vector<int>& a) {
    long long best = LLONG_MIN, cur = 0;
    int bestL = 0, bestR = 0, curL = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (cur + a[i] < a[i]) {
            cur = a[i];
            curL = i;
        } else {
            cur += a[i];
        }
        if (cur > best) {
            best = cur;
            bestL = curL;
            bestR = i;
        }
    }
    return {best, bestL, bestR};
}
