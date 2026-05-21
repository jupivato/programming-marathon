#include <bits/stdc++.h>
using namespace std;

// Encontra o comprimento da LIS em O(N log N)
// Solução padrão para N grande (ex: N <= 10^5)
int lis_nlogn(const vector<int >& arr) {
    if (arr.empty ()) return 0;

    // ’tails ’ armazena a menor "cauda" (último elemento) para uma
    // subsequência crescente de um determinado comprimento.vector<int > tails;
    tails.push_back(arr [0]);

    for (int i = 1; i <arr.size (); i++) {
        int num = arr[i];

        // Se ’num’ é maior que a cauda da LIS mais longa ,
        // ele estende a LIS.if (num > tails.back ()) {
            tails.push_back(num);
        } else {
            // Caso contrário , encontramos a menor cauda que é >= ’num’
            // e a substituímos por ’num ’.Isso nos dá uma LIS de mesmo
            // comprimento , mas com um final menor , aumentando a chance
            // de estendê-la no futuro.auto it = lower_bound(tails.begin (), tails.end(), num);
            *it = num;
        }
    }

    return tails.size ();
}
