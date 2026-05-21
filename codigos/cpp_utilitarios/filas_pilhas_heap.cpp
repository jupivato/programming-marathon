#include <bits/stdc++.h>
using namespace std;

int main() {
    // stack e queue da STL
    stack<int> st;
    st.push(1);
    st.top();
    st.pop();

    queue<int> q;
    q.push(1);
    q.front();
    q.back();
    q.pop();

    // priority_queue = heap: topo é o MAIOR (max-heap)
    priority_queue<int> maxh;
    maxh.push(3);
    maxh.push(1);
    cout << maxh.top() << "\n";  // 3
    maxh.pop();

    // min-heap: inverta o comparador
    priority_queue<int, vector<int>, greater<int>> minh;
    minh.push(3);
    minh.push(1);
    cout << minh.top() << "\n";  // 1

    // heap com pair (ex.: Dijkstra: (dist, vértice))
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({5, 0});
    auto [d, u] = pq.top();
    pq.pop();

    return 0;
}
