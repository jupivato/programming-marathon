#include <bits/stdc++.h>
using namespace std;
int maximum_weight_set(int *vet, int siz)
{
    int memo[siz+1]; // vetor de PD
    memset(memo, 0, sizeof(memo)); // inicializa com 0
    // casos base: nenhum elemento ou apenas o primeiro
    memo[0] = 0;
    memo[1] = vet[0];
    // percorre os elementos do vetor
    for (int i = 2; i <= siz; i++)
    {
        // decide se eh melhor pegar o atual (e somar com i-2)
        // ou ignorar o atual (ficando com o resultado de i-1)
        if (memo[i-1] > memo[i-2] + vet[i-1])
        memo[i] = memo[i-1]; // nao pega o atual
        else
        memo[i] = memo[i-2] + vet[i-1]; // pega o atual
    }
    return memo[siz]; // retorna o maximo valor possivel
}
