#include <bits/stdc++.h>
using namespace std;

int particiona(string *v, int p, int r)
{
    int i = p, j = r + 1;
    string piv = v[p];
    while(1)
    {
        while(v[++i] <piv) if(i == r) break;
        while(piv <v[--j]) if(j == p) break;
        if(i >= j) break;
        string aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
    string aux = v[p];
    v[p] = v[j];
    v[j] = aux;
    return j;
}
void quick(string *v, int p, int r)
{
    int q;
    if(p <r)
    {
        q = particiona(v, p, r);
        quick(v, p, q - 1);
        quick(v, q + 1, r);
    }
}
