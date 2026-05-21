#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
    int id;

    // ordena por x e depois por y em caso de empate
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// produto vetorial
long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    int n;
    if (!(cin >> n)) return;

    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].id = i + 1; // ids
    }

    // o convex hull pede ordenação
    sort(pts.begin(), pts.end());

    if (n <= 2) {
        // se tiver dois pontos, os dois são infinitos
        vector<int> res;
        for (auto p : pts) res.push_back(p.id);
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
        {
          cout << res[i];
          if (i != res.size() - 1) cout << " ";
        }
        cout << endl;
        return;
    }

    vector<Point> hull;

    // constroi o lower hull
    for (int i = 0; i < n; i++) {
        // o <0 serve para remover as curvas para a direita (apenas elas) 
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), pts[i]) < 0) hull.pop_back();
        hull.push_back(pts[i]);
    }

    // constroi o upper hull
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_size && cross_product(hull[hull.size() - 2], hull.back(), pts[i]) < 0) hull.pop_back();
        hull.push_back(pts[i]);
    }

    vector<int> infinite_kingdoms;
    for (int i = 0; i < (int)hull.size() - 1; i++) infinite_kingdoms.push_back(hull[i].id);

    // ordena os ids para printar
    sort(infinite_kingdoms.begin(), infinite_kingdoms.end());
    
    // remove duplicatas
    infinite_kingdoms.erase(unique(infinite_kingdoms.begin(), infinite_kingdoms.end()), infinite_kingdoms.end());

    for (int i = 0; i < infinite_kingdoms.size(); i++) 
    {
        cout << infinite_kingdoms[i];
        if (i != infinite_kingdoms.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
