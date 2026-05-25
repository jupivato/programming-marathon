#include <bits/stdc++.h>
using namespace std;

const int MAX_DIGITS = 20;
const int MAX_SUM = 180;

long long memo_digit[MAX_DIGITS][2][2][MAX_SUM];
string str_N;
int target_sum;

long long solve(int pos, int tight, int lz, int current_sum) {
    if (pos == (int)str_N.size())
        return (current_sum == target_sum) ? 1 : 0;

    if (!tight && memo_digit[pos][tight][lz][current_sum] != -1)
        return memo_digit[pos][tight][lz][current_sum];

    long long ans = 0;
    int limit = tight ? (str_N[pos] - '0') : 9;

    for (int d = 0; d <= limit; d++) {
        int new_tight = tight && (d == limit);
        int new_lz = lz && (d == 0);
        int new_sum = current_sum;
        if (!new_lz || d > 0)
            new_sum += d;
        ans += solve(pos + 1, new_tight, new_lz, new_sum);
    }

    if (!tight)
        memo_digit[pos][tight][lz][current_sum] = ans;
    return ans;
}

long long get_ans(long long N) {
    if (N < 0) return 0;
    str_N = to_string(N);
    memset(memo_digit, -1, sizeof(memo_digit));
    return solve(0, 1, 1, 0);
}

long long solve_range(long long A, long long B) {
    return get_ans(B) - get_ans(A - 1);
}

#ifdef DP_STANDALONE_TEST
int main() {
    target_sum = 10;
    long long A = 10, B = 100;
    cout << solve_range(A, B) << "\n";
    return 0;
}
#endif
