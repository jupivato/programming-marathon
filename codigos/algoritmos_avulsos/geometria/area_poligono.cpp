#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

using Polygon = vector<Point>;

double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Calcula a area de um poligono simples pela formula de Shoelace.
// Os vertices devem estar em ordem horaria ou anti-horaria.
double polygon_area(const Polygon& poly) {
    int n = (int)poly.size();
    if (n < 3) return 0.0;

    double twice_area = 0.0;
    for (int i = 0; i < n; i++) {
        twice_area += cross(poly[i], poly[(i + 1) % n]);
    }
    return fabs(twice_area) / 2.0;
}
