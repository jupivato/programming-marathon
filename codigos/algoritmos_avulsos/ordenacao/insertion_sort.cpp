#include <bits/stdc++.h>
using namespace std;

void insertion (string *vet)
{
    string aux;
    int j;
    for (int i = 1; i <MAX; ++i)
    {
        aux = vet[i];
        for (j = i-1; (j >= 0) && (vet[j] > aux); --j) vet[j+1] = vet[j];
        vet[j+1] = aux;
    }
}
