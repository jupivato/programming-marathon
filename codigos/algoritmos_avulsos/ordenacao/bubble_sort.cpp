#include <bits/stdc++.h>
using namespace std;

void bubble (string *vet)
{
    string aux;
    for(int i = 0; i <MAX; ++i)
    for (int j = 0; j <MAX - i - 1; ++j)
    if(vet[j + 1] <vet[j])
    {
        aux = vet[j];
        vet[j] = vet[j + 1];
        vet[j + 1] = aux;
    }
}
