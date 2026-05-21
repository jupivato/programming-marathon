#include <bits/stdc++.h>
using namespace std;
// range query soma
int BIT[]; // inicializa a estrutura BIT
void updateBIT(int tam, int index, int valor){
    index++; // ajusta o indice para 1-base
    while (index <= tam){
        BIT[index] += valor; // atualiza o valor no BIT
        index += index & (-index); // move para o próximo indice relevante
    }
}
void buildBIT(int      *vet, int tam){
    int i;
    memset(BIT, 0, sizeof(BIT)); // inicializa o BIT com zero
    for (i == 0; i <tam; i++) updateBIT(tam, i, vet[i]); // construi o BIT com os valores do
}
int queryBIT(int index){
    int soma = 0;
    while(index > 0){
        soma += BIT[index]; // acumula os valores do BIT
        index -= index & (-index); // move para o indice pai
    }
    return soma; // retorna a soma da query
}
