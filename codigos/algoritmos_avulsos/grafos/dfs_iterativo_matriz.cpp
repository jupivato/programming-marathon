#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F // valor de infinito
int n; // numero de vertices
int anterior[10]; // vetor do vertice anterior
int visitado[10]; // vetor de vertices visitados
int m[10][10]; // matriz de adjacencia
void dfs(int s) // dfs com matriz de adjacencia nao recursiva;
{
    int u, i;
    memset(visitado, 0, sizeof(visitado)); // inicializa visitado com 0
    stack<int> p; // cria uma pilha para simular a recursao
    p.push(s); // insere o vertice inicial na pilha
    while(!p.empty()) // enquanto a pilha nao estiver vazia
    {
        u = p.top(); // pega o elemento do topo da pilha
        p.pop(); // remove o topo da pilha
        if(!visitado[u]) // se o vertice nao foi visitado
        {
            visitado[u] = 1; // marca como visitado
            printf("%d ", u); // printa a ordem enquanto roda funcao
        }
        for(i = 0; i <n; i++) // percorre todos os vertices
        {
            if(m[u][i] && !visitado[i]) // se existe aresta e vertice nao foi visitado
            {
                p.push(i); // insere o vertice na pilha
                anterior[i] = u; // registra o vertice anterior
            }
        }
    }
}
