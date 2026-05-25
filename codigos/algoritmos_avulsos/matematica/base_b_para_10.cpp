#include <bits/stdc++.h>
using namespace std;

int value_of(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') return c - 'A' + 10;
    if ('a' <= c && c <= 'z') return c - 'a' + 10;
    return -1;
}

long long to_decimal(const string& num, int base) {
    if (base < 2 || base > 36) return -1;

    long long ans = 0;
    for (char c : num) {
        int digit = value_of(c);
        if (digit < 0 || digit >= base) return -1;
        ans = ans * base + digit;
    }
    return ans;
}
