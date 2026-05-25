#include <bits/stdc++.h>
using namespace std;

string from_decimal(long long n, int base) {
    if (base < 2 || base > 36) return "";
    if (n == 0) return "0";

    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans;
    while (n > 0) {
        ans.push_back(digits[n % base]);
        n /= base;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
