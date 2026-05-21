#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Otimização de entrada e saída
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    
    // 1. Criamos um vetor que guarda o menor caractere disponível à direita de cada posição
    // min_sufixo[i] será o menor caractere de s[i] até o fim da string
    vector<char> min_sufixo(n);
    min_sufixo[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        min_sufixo[i] = min(s[i], min_sufixo[i + 1]);
    }

    // 2. Procuramos a primeira posição 'i' onde o caractere atual é maior 
    // que o menor caractere que existe à sua frente.
    int i = 0;
    while (i < n && s[i] <= min_sufixo[i]) {
        i++;
    }

    // Se i == n, a string já é a menor possível (ex: "abc" ou "luz") [cite: 597]
    if (i < n) {
        char menor_letra = min_sufixo[i];
        
        // 3. Procuramos a última ocorrência dessa 'menor_letra' à direita de 'i'
        // para maximizar o ganho da reversão.
        int j = n - 1;
        while (s[j] != menor_letra) {
            j--;
        }

        // 4. Revertemos o intervalo [i, j] 
        reverse(s.begin() + i, s.begin() + j + 1);
    }

    cout << s << endl;

    return 0;
}
