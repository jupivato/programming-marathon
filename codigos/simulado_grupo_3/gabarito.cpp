#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while (cin >> n  && n) 
  {
    while(n--)
    {
      int vet[5];
      int coloridos = 0, pos;
      char saida = '*';
      
      for (int i = 0; i < 5; i++)
      {
        cin >> vet[i];
        if (vet[i] <= 127)
        {
          coloridos++;
          pos = i;
        }
      }
      
      if (coloridos == 1) saida = pos + 65;
      cout << saida << endl;
    }
  }
  return 0;
}

