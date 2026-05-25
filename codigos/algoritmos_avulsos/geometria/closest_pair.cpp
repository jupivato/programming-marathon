#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist_sq(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

double solve(vector<Point>& pts, int l, int r, vector<Point>& aux) {
    if (r - l <= 3) {
        double best = DBL_MAX;
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j < r; j++) {
                best = min(best, dist_sq(pts[i], pts[j]));
            }
        }
        sort(pts.begin() + l, pts.begin() + r, [](Point a, Point b) {
            return a.y < b.y;
        });
        return best;
    }

    int m = (l + r) / 2;
    double mid_x = pts[m].x;
    double best = min(solve(pts, l, m, aux), solve(pts, m, r, aux));

    merge(pts.begin() + l, pts.begin() + m,
          pts.begin() + m, pts.begin() + r,
          aux.begin(), [](Point a, Point b) {
              return a.y < b.y;
          });
    copy(aux.begin(), aux.begin() + (r - l), pts.begin() + l);

    vector<Point> strip;
    for (int i = l; i < r; i++) {
        double dx = pts[i].x - mid_x;
        if (dx * dx < best) strip.push_back(pts[i]);
    }

    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size(); j++) {
            double dy = strip[j].y - strip[i].y;
            if (dy * dy >= best) break;
            best = min(best, dist_sq(strip[i], strip[j]));
        }
    }
    return best;
}

// Retorna a menor distancia euclidiana entre dois pontos.
double closest_pair(vector<Point> pts) {
    if (pts.size() < 2) return DBL_MAX;

    sort(pts.begin(), pts.end(), [](Point a, Point b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<Point> aux(pts.size());
    return sqrt(solve(pts, 0, (int)pts.size(), aux));
}
