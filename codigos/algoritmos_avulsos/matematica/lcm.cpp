#include <bits/stdc++.h>
using namespace std;

long long lcm_ll(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return llabs(a / std::gcd(a, b) * b);
}
