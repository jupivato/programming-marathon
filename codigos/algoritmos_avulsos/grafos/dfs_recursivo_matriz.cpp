#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F // valor de infinito
int n; // numero de vertices
int anterior[10]; // vetor do vertice anterior
int visitado[10]; // vetor de vertices visitados
int m[10][10]; // matriz de adjacencia
void dfs(int u) // dfs com matriz adjacente recursiva
{
    int i;
    if(!visitado[u]) // se o vertice ainda nao foi visitado
    {
        visitado[u] = 1; // marca o vertice como visitado
        printf("%d ", u); // imprime o vertice
    }
    for(i = 0; i <n; i++) // percorre todos os vertices
    {
        if(m[u][i] && !visitado[i]) // se existe aresta e vertice nao foi visitado
        {
            anterior[i] = u; // registra o vertice anterior
            dfs(i); // chamada recursiva para o proximo vertice
        }
    }
}
