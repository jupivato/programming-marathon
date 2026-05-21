#include <bits/stdc++.h>

using namespace std;

int x;
vector<int>ordem;

int main()
{
  cin >> x;
  int vet[x];
  for (int i = 0; i < x; i++) cin >> vet[i];
  for (int i = 0; i <= x; i++) ordem.push_back(i);
  int i = 0;
  while(i != x)
  {
    cout << ordem[vet[i]];
    if (i != x - 1) cout << " ";
    for (int j = vet[i]; j <= x; j++) ordem[j] -= 1;
    i++;
  }
  cout << endl;
  return 0;
}
