#include <bits/stdc++.h>
using namespace std;

// prefix[i] = soma de arr[0..i-1]; prefix[0] = 0
vector<long long> buildPrefix(const vector<int>& arr) {
    vector<long long> pref(arr.size() + 1, 0);
    for (int i = 0; i < (int)arr.size(); i++)
        pref[i + 1] = pref[i] + arr[i];
    return pref;
}

// soma de arr[l..r] inclusive (indices 0-based)
long long rangeSum(const vector<long long>& pref, int l, int r) {
    return pref[r + 1] - pref[l];
}

// exemplo: quantos subarrays tem soma exatamente k (funciona com negativos)
int countSubarraySumK(const vector<int>& arr, int k) {
    unordered_map<long long, int> freq;
    freq[0] = 1;
    long long sum = 0;
    int ans = 0;
    for (int x : arr) {
        sum += x;
        if (freq.count(sum - k))
            ans += freq[sum - k];
        freq[sum]++;
    }
    return ans;
}
