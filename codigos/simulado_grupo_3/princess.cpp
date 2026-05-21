#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> princesa(3);
    vector<int> principe(2);

    while(cin >> princesa[0] >> princesa[1] >> princesa[2] >> principe[0] >> principe[1] && princesa[0] != 0)
    {
        
        sort(princesa.begin(), princesa.end());
        int servo = -1;

        for(int carta = 1; carta <= 52; carta++)
        {
            if(carta != princesa[0] && carta != princesa[1] && carta != princesa[2] && carta != principe[0] && carta != principe[1])
            {
                vector<int> teste = {principe[0], principe[1], carta};
                sort(teste.begin(), teste.end());
                if(teste[0] > princesa[1] || teste[1] > princesa[2])
                {
                    servo = carta;
                    break;
                }
            }
        }
        cout << servo << "\n";
    }
    return 0;
}
