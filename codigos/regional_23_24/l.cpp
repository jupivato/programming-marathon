#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int k;
    
    cin >> s >> k;
    
    int n = s.length();
    vector<vector<char>> grupos(k);
    
    for (int i = 0; i < n; i++) grupos[i % k].push_back(s[i]);
    for (int i = 0; i < k; i++) sort(grupos[i].begin(), grupos[i].end());
    
    vector<int> pointers(k, 0); // todos os k subgrupos começam apontando pra 0
    string result = s;
    
    for (int i = 0; i < n; i++) 
    {
        int group_idx = i % k;
        result[i] = grupos[group_idx][pointers[group_idx]];
        pointers[group_idx]++;
    }
    
    cout << result << endl;
    return 0;
}
