#include <bits/stdc++.h>
using namespace std;

struct Ponto {
    double x, y;
};

// dot(u,v) = x1*x2 + y1*y2
double dot(Ponto u, Ponto v) {
    return u.x * v.x + u.y * v.y;
}

// cross(u,v) escalar 2D = x1*y2 - y1*x2
double cross(Ponto u, Ponto v) {
    return u.x * v.y - u.y * v.x;
}

// d = sqrt((x2-x1)^2 + (y2-y1)^2)
double distancia(Ponto a, Ponto b) {
    return hypot(a.x - b.x, a.y - b.y);
}

// cos(theta) = dot(u,v) / (|u||v|)
double cos_angulo(Ponto u, Ponto v) {
    return dot(u, v) / (distancia({0, 0}, u) * distancia({0, 0}, v));
}

// Area triangulo = | (B-A) x (C-A) | / 2
double area_triangulo(Ponto a, Ponto b, Ponto c) {
    return abs(cross({b.x - a.x, b.y - a.y}, {c.x - a.x, c.y - a.y})) / 2.0;
}

// Heron: sqrt(s(s-a)(s-b)(s-c)), s = (a+b+c)/2
double area_heron(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Area poligono (shoelace)
double area_poligono(const vector<Ponto>& p) {
    int n = p.size();
    double s = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return abs(s) / 2.0;
}

// Distancia ponto (x0,y0) a reta Ax+By+C=0
double dist_ponto_reta(double x0, double y0, double A, double B, double C) {
    return abs(A * x0 + B * y0 + C) / hypot(A, B);
}
