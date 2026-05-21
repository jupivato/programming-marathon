#include<bits/stdc++.h>

using namespace std;

int main()
{
  vector<int>princess;
  vector<int>prince;
  int vet[52] = {0};
  
  for (int i = 0; i < 3; i++)
  {
    int aux;
    cin >> aux;
    princess.push_back(aux);
    vet[aux] = 1;
  }
  
  for (int i = 0; i < 2; i++)
  {
    int aux;
    cin >> aux;
    prince.push_back(aux);
    vet[aux] = 1;
  }
  
  while (princess[0] || princess[1] || princess[2] || prince[0] || prince[1])
  {
    sort(princess.begin(), princess.end());
    sort(prince.begin(), prince.end());
    reverse(princess.begin(), princess.end());
    
    for (int i = 0; i < 3; i++) cout << princess[i] << '-' << prince[i] << endl;
    int pontos_princesa = 0;
    int pontos_principe = 0;

    for(int i = 0; i < 2; i++)
    {
      if (princess[i] > prince[i]) pontos_princesa++;
      else pontos_principe++;
    }
    
    int comparacao_final = princess[2];
    
    if (pontos_principe)
    {
      while (comparacao_final <= 52 && vet[comparacao_final] != 0) comparacao_final++;
      if (comparacao_final > 52) cout << "-1" << endl;
      else cout << comparacao_final << endl;
    }
    else if (pontos_principe < pontos_princesa) cout << "-1" << endl;
  
    for (int i = 0; i < 3; i++)
    {
      int aux;
      cin >> aux;
      princess.push_back(aux);
    }
    for (int i = 0; i < 2; i++)
    {
      int aux;
      cin >> aux;
      prince.push_back(aux);
    }
    princess.clear();
    prince.clear();
    vet[52] = {0};
  }
  return 0;
}
