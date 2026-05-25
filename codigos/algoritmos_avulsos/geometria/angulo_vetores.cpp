#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

struct Point {
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator-(const Point& p) const { return {x - p.x, y - p.y}; }
};

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Retorna o angulo PQR, com vertice em Q, em radianos.
double angle(Point p, Point q, Point r) {
    Point u = p - q;
    Point v = r - q;
    return atan2(cross(u, v), dot(u, v));
}

double to_degrees(double radians) {
    return radians * 180.0 / PI;
}
