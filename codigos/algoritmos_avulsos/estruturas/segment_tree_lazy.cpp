#include <bits/stdc++.h>
using namespace std;

// Segment tree com lazy propagation para soma em intervalo
// Parametros: init_segment_tree_lazy(arr), update_range(l, r, delta), query_range(l, r)
// Retorna: soma no intervalo [l, r] (0-based, inclusivo)
vector<long long> seg_lazy, lazy;
int seg_lazy_n = 0;

void build_lazy(const vector<long long>& arr, int node, int l, int r) {
    if (l == r) {
        seg_lazy[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build_lazy(arr, node * 2, l, mid);
    build_lazy(arr, node * 2 + 1, mid + 1, r);
    seg_lazy[node] = seg_lazy[node * 2] + seg_lazy[node * 2 + 1];
}

void init_segment_tree_lazy(const vector<long long>& arr) {
    seg_lazy_n = (int)arr.size();
    seg_lazy.assign(seg_lazy_n * 4, 0);
    lazy.assign(seg_lazy_n * 4, 0);
    if (seg_lazy_n > 0) build_lazy(arr, 1, 0, seg_lazy_n - 1);
}

void push(int node, int l, int r) {
    if (lazy[node] == 0) return;
    seg_lazy[node] += (r - l + 1) * lazy[node];
    if (l != r) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node, int l, int r, int ql, int qr, long long delta) {
    push(node, l, r);
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        lazy[node] += delta;
        push(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_range(node * 2, l, mid, ql, qr, delta);
    update_range(node * 2 + 1, mid + 1, r, ql, qr, delta);
    seg_lazy[node] = seg_lazy[node * 2] + seg_lazy[node * 2 + 1];
}

void update_range(int l, int r, long long delta) {
    if (seg_lazy_n == 0) return;
    update_range(1, 0, seg_lazy_n - 1, l, r, delta);
}

long long query_range(int node, int l, int r, int ql, int qr) {
    push(node, l, r);
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg_lazy[node];
    int mid = (l + r) / 2;
    return query_range(node * 2, l, mid, ql, qr) +
           query_range(node * 2 + 1, mid + 1, r, ql, qr);
}

long long query_range(int l, int r) {
    if (seg_lazy_n == 0) return 0;
    return query_range(1, 0, seg_lazy_n - 1, l, r);
}
