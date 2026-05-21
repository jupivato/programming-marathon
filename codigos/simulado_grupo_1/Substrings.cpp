#include <bits/stdc++.h>

using namespace std;

int maiorSubstringComum(const string& s1, const string& s2) 
{
  int n = s1.length();
  int m = s2.length();
  int max_len = 0;
  
  // matriz com todas as comparações - inicializa em zeros
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      // se os caracteres baterem (case-sensitive)
      if (s1[i - 1] == s2[j - 1]) 
      {
        dp[i][j] = dp[i - 1][j - 1] + 1; // aumenta o tamanho da substring contínua
        max_len = max(max_len, dp[i][j]); // atualiza o máximo local desta dupla de strings
      }
    }
  }
  return max_len;
}

int main() 
{
  string s1, s2;
  int recorde_global = 0;

  while (getline(cin, s1) && getline(cin, s2)) 
  {
    int recorde_local = maiorSubstringComum(s1, s2);
    recorde_global = max(recorde_global, recorde_local);
  }

  cout << recorde_global << endl;
  return 0;
}
