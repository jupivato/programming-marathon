#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, k, cont = 0;
  cin >> n >> k;
  
  vector<int>vet;
  
  for (int i = 0; i < n; i++)
  {
    int aux;
    cin >> aux;
    vet.push_back(100 - aux);
  }
  
  sort(vet.begin(), vet.end());
  
  for (int i = 0; i < n; i++)
  {
    if (k >= vet[i])
    {
      k-=vet[i];
      cont++;
    }
    else break;
  }
  cout << cont << endl;
  return 0;
}
