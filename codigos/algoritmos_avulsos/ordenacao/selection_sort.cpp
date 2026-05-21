#include <bits/stdc++.h>
using namespace std;

void selection (string *vet){
    string aux;
    int menor;
    for(int i = 0; i <MAX-1; ++i)
    {
        menor = i;
        for (int j = (i+1); j <MAX; ++j)
        if (vet[j] <vet[menor]) menor = j;
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}
