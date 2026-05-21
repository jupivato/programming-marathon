#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector: array dinamico - o mais usado
    vector<int> v(5, 0);     // cinco zeros
    v.push_back(10);
    v.pop_back();
    v.resize(10);
    v.clear();

    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";

    // range-for (percorre cópia ou referência)
    for (int x : v) cout << x << " ";
    for (int& x : v) x++;    // altera o vetor
    for (const int& x : v) cout << x << " ";

    // deque: inserir/remover nas duas pontas em O(1)
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(0);
    dq.pop_front();
    dq.pop_back();

    return 0;
}
