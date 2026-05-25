#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

long long cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Sinal da orientacao de a -> b -> c.
int orientation(Point a, Point b, Point c) {
    long long v = cross(b - a, c - a);
    if (v > 0) return 1;
    if (v < 0) return -1;
    return 0;
}
