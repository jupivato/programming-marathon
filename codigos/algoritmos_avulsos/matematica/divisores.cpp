#include <bits/stdc++.h>
using namespace std;

vector<long long> divisors(long long n) {
    vector<long long> ans;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            ans.push_back(d);
            if (d * d != n) ans.push_back(n / d);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
