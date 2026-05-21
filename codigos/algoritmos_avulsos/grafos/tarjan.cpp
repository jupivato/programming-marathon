#include <bits/stdc++.h>
using namespace std;
// componente fortemente conexo
vector<int> adj[]; // vetor de adjacencia para o grafo
stack<int> s; // pilha usada no algoritmo de tarjan
int c, t, dis[], low[], ins[]; // variaveis para controle das descobertas, tempos e pilha
set<int> comp[]; set<int>::iterator sit; // conjunto de componentes fortemente conexos
// funcao que faz a dfs e encontra os componentes fortemente conexos
void DFS(int u){
    dis[u] = low[u] = t++; // marca o tempo de descoberta
    s.push(u); ins[u] = 1; // adiciona o no na pilha e marca como no da pilha
    vector<int>::iterator it;
    for(it = adj[u].begin(); it != adj[u].end(); it++){
        int v = *it;
        if(dis[v] == -1){
            DFS(v); // chamada recursiva para o vizinho
            low[u] = min(low[u], low[v]); // atualiza o low do no u
        }
        else if(ins[v] == 1) low[u] = min(low[u], dis[v]); // se o vizinho esta na pilha
    }
    if (low[u] == dis[u]){ // encontrou um componente fortemente conexo
        int w = 0;
        while (s.top() != u){ // desempilha os nos do componente
            w = s.top();
            comp[c].insert(w); ins[w] = 0; s.pop();
        }
        w = s.top();
        comp[c].insert(w); ins[w] = 0; s.pop();
        c++; // incrementa o numero do componente
    }
}
// funcao que inicia a busca de tarjan
void tarjan(int n){
    t = c = 0; // inicializa os temporizadores e contador de componentes
    for (int i = 0; i <n; i++){
        dis[i] = low[i] = -1; ins[i] = 0; comp[i].clear(); // inicializa os valores
    }
    for(int i = 0; i <n; i++) if (dis[i] == -1) DFS(i); // chama dfs para todos os nos ainda
}
