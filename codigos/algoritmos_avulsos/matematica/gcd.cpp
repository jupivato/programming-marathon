#include <bits/stdc++.h>
using namespace std;

long long gcd_ll(long long a, long long b) {
    a = llabs(a);
    b = llabs(b);
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
