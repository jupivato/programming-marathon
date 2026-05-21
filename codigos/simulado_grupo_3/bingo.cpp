#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, b;

    while (cin >> n >> b && (n || b)) 
    {
        vector<int>bolas(b);
        set<int>diferencas_encontradas;

        for (int i = 0; i < b; i++) cin >> bolas[i];

        for (int i = 0; i < b; i++) 
        {
            for (int j = i; j < b; j++) 
            {
                int dif = abs(bolas[i] - bolas[j]);
                if (dif <= n) diferencas_encontradas.insert(dif);
            }
        }

        if (diferencas_encontradas.size() == n + 1) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}

