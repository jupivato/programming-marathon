#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

int cmp(double a, double b = 0.0) {
    if (fabs(a - b) <= EPS) return 0;
    return a < b ? -1 : 1;
}

struct Point {
    double x, y;

    bool operator<(const Point& p) const {
        if (cmp(x, p.x) != 0) return x < p.x;
        return y < p.y;
    }
};

Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

int ccw(Point a, Point b, Point c) {
    return cmp(cross(b - a, c - a));
}

// Retorna os pontos do fecho convexo em ordem anti-horaria.
vector<Point> convex_hull(vector<Point> pts, bool include_collinear = false) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end(), [](Point a, Point b) {
        return cmp(a.x, b.x) == 0 && cmp(a.y, b.y) == 0;
    }), pts.end());

    if (pts.size() <= 1) return pts;

    vector<Point> lower, upper;
    for (Point p : pts) {
        while (lower.size() >= 2) {
            int turn = ccw(lower[lower.size() - 2], lower.back(), p);
            if (turn < 0 || (turn == 0 && !include_collinear)) lower.pop_back();
            else break;
        }
        lower.push_back(p);
    }

    for (int i = (int)pts.size() - 1; i >= 0; i--) {
        Point p = pts[i];
        while (upper.size() >= 2) {
            int turn = ccw(upper[upper.size() - 2], upper.back(), p);
            if (turn < 0 || (turn == 0 && !include_collinear)) upper.pop_back();
            else break;
        }
        upper.push_back(p);
    }

    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}
