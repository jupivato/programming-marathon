#include <bits/stdc++.h>
using namespace std;

int mod_pow(long long a, long long e, int m) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = res * a % m;
        a = a * a % m;
        e>>= 1;
    }
    return res;
}
int mod_inv_prime (int a, int m) {
    return mod_pow(a, m - 2, m);
}
