#include <bits/stdc++.h>
using namespace std;
void heapfy (int * vet, int n, int i)
{
    int esq = 2 * i + 1; // filho do lado esquerdo
    int dir = 2 * i + 2; // filho do lado direito
    int maior, aux;
    //escolhe o maior valor entre os filhos esq e dir
    maior = i;
    if ((esq <n) && (vet[esq] > vet[maior])) maior = esq;
    if ((dir <n) && (vet[dir] > vet[maior])) maior = dir;
    // se um dos filhos for maior que o pai, troca
    if (maior != i)
    {
        aux = vet[i];
        vet[i] = vet[maior];
        vet[maior] = aux;
        // continua descida ate local adequado
        heapfy(vet, n, maior);
    }
}
void create_heap (int *vet, int n)
{
    // ajusta heap de baixo para cima
    for (int i = n/2-1; i >= 0; i--)
    heapfy(vet, n, i);
}
void heapsort (int *vet, int n)
{
    int aux;
    create_heap (vet, n);
    for (int i = n-1; i > 0; i--)
    {
        // troca o primeiro (maior) com ultimo
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        n--; // diminui tamanho da heap (ultimo elemento ja foi ordenado)
        heapfy(vet, n, 0); // ajusta heap (leva elemento do topo ate seu lugar)
    }
}
