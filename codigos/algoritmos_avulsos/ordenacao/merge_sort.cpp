#include <bits/stdc++.h>
using namespace std;

void intercala(string *v, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    string *left = new string[n1];
    string *right = new string[n2];
    for (int i = 0; i <n1; i++) left[i] = v[p + i];
    for (int j = 0; j <n2; j++) right[j] = v[q + 1 + j];
    int i = 0, j = 0, k = p;
    while (i <n1 && j <n2)
    {
        if (left[i] <= right[j]) v[k++] = left[i++];
        else v[k++] = right[j++];
    }
    while (i <n1) v[k++] = left[i++];
    while (j <n2) v[k++] = right[j++];
    delete[] left;
    delete[] right;
}
void merge(string *v, int p, int r)
{
    if (p <r)
    {
        int q = (p + r) / 2;
        merge(v, p, q);
        merge(v, q + 1, r);
        intercala(v, p, q, r);
    }
}
