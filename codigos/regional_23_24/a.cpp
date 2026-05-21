#include <bits/stdc++.h>

using namespace std;

int main()
{
  int numero, altura, cont = 0;
  cin >> numero >> altura;
  while (numero--)
  {
    int aux;
    cin >> aux;
    if (altura >= aux) cont++;
  }
  cout << cont << endl;
  return 0;
}
