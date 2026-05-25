#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);

int cmp(double a, double b = 0.0) {
    if (fabs(a - b) <= EPS) return 0;
    return a < b ? -1 : 1;
}

struct Point {
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator+(const Point& p) const { return {x + p.x, y + p.y}; }
    Point operator-(const Point& p) const { return {x - p.x, y - p.y}; }
    Point operator*(double k) const { return {x * k, y * k}; }
    Point operator/(double k) const { return {x / k, y / k}; }

    bool operator<(const Point& p) const {
        if (cmp(x, p.x) != 0) return x < p.x;
        return y < p.y;
    }
};

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double norm(Point a) {
    return hypot(a.x, a.y);
}

int ccw(Point a, Point b, Point c) {
    return cmp(cross(b - a, c - a));
}

bool on_segment(Point p, Point a, Point b) {
    return ccw(a, b, p) == 0 && cmp(dot(a - p, b - p)) <= 0;
}

bool segments_intersect(Point a, Point b, Point c, Point d) {
    int o1 = ccw(a, b, c), o2 = ccw(a, b, d);
    int o3 = ccw(c, d, a), o4 = ccw(c, d, b);

    if (o1 * o2 < 0 && o3 * o4 < 0) return true;
    if (o1 == 0 && on_segment(c, a, b)) return true;
    if (o2 == 0 && on_segment(d, a, b)) return true;
    if (o3 == 0 && on_segment(a, c, d)) return true;
    if (o4 == 0 && on_segment(b, c, d)) return true;
    return false;
}

double dist_point_segment(Point p, Point a, Point b) {
    if (cmp(dot(p - a, b - a)) <= 0) return norm(p - a);
    if (cmp(dot(p - b, a - b)) <= 0) return norm(p - b);
    return fabs(cross(b - a, p - a)) / norm(b - a);
}
