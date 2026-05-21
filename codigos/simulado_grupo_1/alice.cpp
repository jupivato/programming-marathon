#include <bits/stdc++.h>

using namespace std;

int main() 
{
  int T;
  while (true) {
    cin >> T;
    if (T == 0) return 0;
    
    vector<pair<long long int, long long int>> pontos;
    
    for (int i = 0; i < T; ++i) {
      long long int x, y;
      cin >> x >> y;
      if (x == 0 && y == 0) continue;
      pontos.push_back({x, y});
    }
    
    sort(pontos.begin(), pontos.end());

    for (const auto& p : pontos) cout << p.first << " " << p.second << endl;
    cout << endl;
  }
}
