#include <bits/stdc++.h>
using namespace std;

void shell (string *vet)
{
    string aux;
    int j, h;
    h = MAX / 2;
    while (h >= 1)
    {
        for (int i = 1; i <MAX; ++i)
        {
            aux = vet[i];
            for (j = i - h; (j >= 0) && (vet[j] > aux); j = j - h)
            vet[j + h] = vet[j];
            vet[j+h] = aux;
        }
        h = h/2;
    }
}
