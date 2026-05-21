#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    long long int par = 1, impar = 0, prefix_sum = 0, total = 0;
    
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        prefix_sum += x;

        if (prefix_sum % 2 != 0) 
        {
            // se o prefixo atual é impar, soma com todos os pares anteriores
            total += par; 
            impar++; // soma mais um registro impar
        } 
        else 
        {
            // se o prefixo atual é par, soma com todos os ímpares anteriores
            total += impar;
            par++; // soma mais um registro par
        }
    }

    cout << total << endl;
    return 0;
}
