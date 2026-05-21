#include <bits/stdc++.h>
using namespace std;

// Componentes Fortemente Conexos (Kosaraju) - O(V + E)

// ’visitado ’ rastreia os vértices que já foram visitados na DFS atual.vector<bool > visitado;

// Executa uma busca em profundidade a partir do vértice v.
// Cada vértice visitado é adicionado ao vetor ’saida ’ quando a DFS o deixa (pós-ordem).void dfs(int v, const vector<vector<int>>& adj , vector<int >& saida) {
    visitado[v] = true;
    for (int u : adj[v]) { 2.10 Algoritmo de Kruskal (Minimum Spanning Tree) A verificação de ciclos é feita de forma eficiente com uma estrutura Union- Find (DSU).A complexidade final do algoritmo é dominada pela ordenação das arestas: O(E logE).if (! visitado[u]) {
        dfs(u, adj , saida);
    }
}
saida.push_back(v);
}

// entrada: adj -- lista de adjacência do grafo G
// saida: componentes -- os componentes fortemente conexos de G
// saida: adj_condensado -- lista de adjacência do grafo de condensação G^SCC
void encontrar_sccs (const vector<vector<int>>& adj ,
vector<vector<int>>& componentes ,
vector<vector<int>>& adj_condensado ) {
    int n = adj.size ();
    componentes.clear ();
    adj_condensado.clear ();

    // ’ordem ’ será uma lista dos vértices de G ordenados pelo tempo de finalização.vector<int > ordem;
    visitado.assign(n, false);

    // Primeira série de buscas em profundidade no grafo original.for (int i = 0; i <n; i++) {
        if (! visitado[i]) {
            dfs(i, adj , ordem);
        }
    }

    // Cria a lista de adjacência do grafo transposto (G^T).vector<vector<int>> adj_reverso(n);
    for (int v = 0; v <n; v++) {
        for (int u : adj[v]) {
            adj_reverso[u].push_back(v);
        }
    }

    visitado.assign(n, false);
    reverse(ordem.begin (), ordem.end());

    // ’raiz_componente ’ indica o vértice raiz do SCC de um determinado vértice.vector<int > raiz_componente (n);

    // Segunda série de buscas em profundidade , no grafo transposto.for (int v : ordem) {
        if (! visitado[v]) {
            vector<int > componente_atual ;
            dfs(v, adj_reverso , componente_atual );

            componentes.push_back( componente_atual );
            int raiz = componente_atual [0];
            for (int u : componente_atual ) {
                raiz_componente [u] = raiz;
            }
        }
    }

    // Adiciona as arestas ao grafo de condensação.adj_condensado .assign(n, {});
    for (int v = 0; v <n; v++) {
        for (int u : adj[v]) {
            if ( raiz_componente [v] != raiz_componente [u]) {
                adj_condensado [ raiz_componente [v]].push_back( raiz_componente [u]);
            }
        }
    }
}
