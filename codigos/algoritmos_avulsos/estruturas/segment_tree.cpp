#include <bits/stdc++.h>
using namespace std;

// Segment tree para soma em intervalo com update pontual
// Parametros: init_segment_tree(arr), query_segment_tree(l, r), update_segment_tree(idx, val)
// Retorna: soma no intervalo [l, r] (0-based, inclusivo)
vector<long long> seg;
int seg_n = 0;

void build_segment_tree(const vector<long long>& arr, int node, int l, int r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build_segment_tree(arr, node * 2, l, mid);
    build_segment_tree(arr, node * 2 + 1, mid + 1, r);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void init_segment_tree(const vector<long long>& arr) {
    seg_n = (int)arr.size();
    seg.assign(seg_n * 4, 0);
    if (seg_n > 0) build_segment_tree(arr, 1, 0, seg_n - 1);
}

long long query_segment_tree(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return query_segment_tree(node * 2, l, mid, ql, qr) +
           query_segment_tree(node * 2 + 1, mid + 1, r, ql, qr);
}

long long query_segment_tree(int l, int r) {
    if (seg_n == 0) return 0;
    return query_segment_tree(1, 0, seg_n - 1, l, r);
}

void update_segment_tree(int node, int l, int r, int idx, long long val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update_segment_tree(node * 2, l, mid, idx, val);
    else update_segment_tree(node * 2 + 1, mid + 1, r, idx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void update_segment_tree(int idx, long long val) {
    if (seg_n == 0) return;
    update_segment_tree(1, 0, seg_n - 1, idx, val);
}
