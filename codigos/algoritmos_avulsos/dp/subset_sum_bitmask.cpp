#include <bits/stdc++.h>
using namespace std;

// Existe subconjunto com soma alvo? n <= 22 tipico
bool subsetSumBitmask(const vector<int>& a, int target) {
    int n = a.size();
    int total = 0;
    for (int x : a) total += x;
    if (target < 0 || target > total) return false;

    int limit = 1 << n;
    for (int mask = 0; mask < limit; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) sum += a[i];
        if (sum == target) return true;
    }
    return false;
}

// Mochila 0/1 por bitmask: max valor com peso <= W, n pequeno
int knapsackBitmask(const vector<int>& peso, const vector<int>& valor, int W) {
    int n = peso.size();
    int best = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int w = 0, v = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                w += peso[i];
                v += valor[i];
            }
        }
        if (w <= W) best = max(best, v);
    }
    return best;
}
