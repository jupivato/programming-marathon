#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;


int main() {

  int t;
  cin >> t;
  while (t--) 
  {
    int N, M;
    cin >> N >> M;

    vector<int> gomos(N);
    for (int i = 0; i < N; ++i) cin >> gomos[i];

    // dp[i] guarda o mínimo de gomos pro comprimento i (tundo infinito menos o zero)
    vector<int> dp(M + 1, INF);
    
    dp[0] = 0;

    // atualiza dp[i] p/ cada gomo
    for (int c : gomos)
      for (int i = c; i <= M; ++i) 
        if (dp[i - c] != INF) dp[i] = min(dp[i], dp[i - c] + 1);
        // pergunta o quanto falta para chegar no valor, se der pra substituir por apenas mais um gomo do novo valor, faz a troca

    cout << dp[M] << endl;
  }
  return 0;
}
