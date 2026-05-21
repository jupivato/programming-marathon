#include <bits/stdc++.h>
using namespace std;
void counting_sort (int *vet)
{
    // inicializa vetor auxiliar (conta elementos)
    int aux[k];
    for (int i = 0; i <k; i++) aux[i] = 0;
    // conta a quantidade de elementos iguais a vet[i];
    for (int i = 0; i <n; i++) aux[vet[i]] += 1;
    // conta a quantidade de elementos iguais ou menores
    for (int i = 1; i <k; i++) aux[i] += aux[i+1];
    // preenche vetor de saida
    int out[n];
    for (int i = n-1; i >= 0; i--)
    {
        out[aux[vet[i]]-1] = vet[i]; // vetor começa em zero
        aux[vet[i]] -= 1;
    }
}
