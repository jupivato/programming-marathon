#include <bits/stdc++.h>
using namespace std;

int main() {
    // STACK (pilha): ultimo que entra, primeiro que sai - LIFO
    stack<int> st;
    st.push(10);
    st.push(20);
    int topo = st.top();   // 20 (o ultimo inserido)
    st.pop();              // remove 20; st.top() agora seria 10
    // NAO existe st[0] nem percorrer com for

    // QUEUE (fila): primeiro que entra, primeiro que sai - FIFO
    queue<int> q;
    q.push(1);
    q.push(2);
    int frente = q.front();  // 1
    int tras = q.back();     // 2
    q.pop();                 // remove 1

    // PRIORITY_QUEUE: sempre acessa o MAIOR (max-heap)
    priority_queue<int> pq;
    pq.push(3);
    pq.push(10);
    pq.push(5);
    cout << pq.top() << "\n";  // 10
    pq.pop();

    // Min-heap: menor no topo
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(3);
    minpq.push(10);
    cout << minpq.top() << "\n";  // 3

    // Par (distancia, vertice) - Dijkstra
    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> dij;
    dij.push({5, 0});
    dij.push({2, 3});
    // topo: menor .first (distancia)

    return 0;
}
