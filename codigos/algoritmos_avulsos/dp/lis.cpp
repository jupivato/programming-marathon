#include <bits/stdc++.h>
using namespace std;

// LIS O(n log n) - tails + lower_bound
int lis_nlogn(const vector<int>& arr) {
    if (arr.empty()) return 0;

    vector<int> tails;
    tails.push_back(arr[0]);

    for (size_t i = 1; i < arr.size(); i++) {
        int num = arr[i];
        if (num > tails.back()) {
            tails.push_back(num);
        } else {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            *it = num;
        }
    }
    return (int)tails.size();
}
