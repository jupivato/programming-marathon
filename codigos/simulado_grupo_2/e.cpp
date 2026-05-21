#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  long long int vet[71];
  cin >> n;
  vet[0] = 1;
  vet[1] = 1;
  vet[2] = 2;
  vet[3] = 4;
  for (int i = 4; i <= n; i++)
    vet[i] = vet[i-1] + vet[i-2] + vet[i-3];
  cout << vet[n] << endl;
  return 0;
}
