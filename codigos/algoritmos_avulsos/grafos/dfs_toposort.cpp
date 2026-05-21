#include <bits/stdc++.h>
#define INF 0x3F3F3F3F // valor de infinito
using namespace std;
int n; // numero de vertices
int anterior[10]; // vetor do vertice anterior
int visitado[10]; // vetor de vertices visitados
vector<pair<int,int>> adj[10]; // lista de adjacencias
void dfs(int u)
{
    if(!visitado[u]) // se o vertice nao foi visitado
    {
        visitado[u] = 1; // marca o vertice como visitado
        printf("%d ", u); // printa a ordem enquanto roda a funcao
        for(auto i : adj[u]) dfs(i.first); // chama dfs para os vizinhos
    }
}
