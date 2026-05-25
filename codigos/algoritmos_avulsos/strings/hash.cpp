#include <bits/stdc++.h>
using namespace std;

// Constantes seguras: modulos primos grandes e bases impares
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long BASE1 = 313;
const long long BASE2 = 317;

struct StringHash {
    vector<long long > h1 , h2;
    vector<long long > p1 , p2;
    int n;

    // Construtor: pre-calcula os prefixos e as potencias em O(n)
    StringHash(const string& s) {
        n = s.size ();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        for (int i = 0; i <n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + s[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + s[i]) % MOD2;

            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }
    }

    // Retorna o hash da substring s[L...R] (0-indexado) em O(1)
    pair<long long , long long > get_hash(int L, int R) {
        long long hash1 = (h1[R + 1] - (h1[L] * p1[R - L + 1]) % MOD1 + MOD1) % MOD1;
        long long hash2 = (h2[R + 1] - (h2[L] * p2[R - L + 1]) % MOD2 + MOD2) % MOD2;
        return {hash1 , hash2 };
    }
};

/* // --- Exemplo de Uso ---
int main () {
    string texto = "abracadabra ";
    StringHash sh(texto);

    // Pegando o hash de "abr" no inicio e no meio da palavra
    auto hash_prefixo = sh.get_hash (0, 2); // "abr"
    auto hash_meio = sh.get_hash (7, 9); // "abr"

    if (hash_prefixo == hash_meio) {
        cout << "As substrings sao iguais!\n";
    }
    return 0;
}
*/
