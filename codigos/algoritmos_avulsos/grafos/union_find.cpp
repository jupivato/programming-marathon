#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100001;
int link[N_MAX ];
int size[N_MAX ];

// Função para encontrar o representante do conjunto
int find(int x) {
    return (x == link[x]) ? x : (link[x] = find(link[x]));
}

// Função para verificar se dois elementos estão no mesmo conjunto
bool same(int x, int y) {
    return find(x) == find(y);
}

// Função para unir dois conjuntos
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size[a] <size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}
// exemplo na main
int main () {

    int N, K, i, x1 , x2;
    char op;

    cin>> N>> K;

    // Inicialização da estrutura DSU
    for (i = 0; i <N; ++i) {
        link[i] = i;
        size[i] = 1;
    }

    for (i = 0; i <K; ++i) {
        cin>> op>> x1>> x2;
        if (op == ’C’) {
            if (same(x1 , x2)) {
                cout <<"S" <<’\n’;
            } else {
                cout <<"N" <<’\n’;
            }
        } else { // ’U’
        if(! same(x1 , x2))unite(x1 , x2);
    }
}

return 0;
}
