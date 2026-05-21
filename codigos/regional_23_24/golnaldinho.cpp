#include <bits/stdc++.h>

using namespace std;

struct num{
  int n;
  prox num;
}numero;

int main()
{
  int x;
  cin >> x;
  numero numeros[x];
  vet[0] = 0;
  for (int i = 0; i < x - 1; i++) numeros[i].prox = i+1;
  for (int i = 1; i < x; i++) vet[i] = i + vet[i-1];
  
  
  return 0;
}
