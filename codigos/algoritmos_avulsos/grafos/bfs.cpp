#include <bits/stdc++.h>
#define INF 0x3F3F3F3F // valor de infinito
using namespace std;
int n; // numero de vertices
int anterior[10]; // vetor do vertice anterior
int visitado[10]; // vetor de vertices visitados
int m[10][10]; // matriz de adjacencia
void bfs(int s)
{
    int i, u;
    memset(visitado, 0, sizeof(visitado)); // inicializa visitado com 0
    queue<int> q;
    q.push(s); // insere o vertice inicial na fila
    visitado[s] = 1; // marca o vertice inicial como visitado
    anterior[s] = -1; // vertice inicial nao tem anterior
    while(!q.empty()) // enquanto a fila nao estiver vazia
    {
        u = q.front(); // pega o primeiro elemento da fila
        q.pop(); // remove o elemento da fila
        cout <<u; // imprime o vertice atual
        for(i = 0; i <n; i++) // percorre todos os vertices
        {
            if(m[u][i] && !visitado[i]) // se existe aresta e vertice nao foi visitado
            {
                q.push(i); // insere o vertice na fila
                visitado[i] = 1; // marca como visitado
                anterior[i] = u; // registra o vertice anterior
            }
        }
    }
}
