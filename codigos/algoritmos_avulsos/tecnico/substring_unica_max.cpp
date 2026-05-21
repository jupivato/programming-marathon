#include <bits/stdc++.h>
using namespace std;
int longestUniqueSubstring(string s) {
    unordered_set<char> chars; // conjunto para armazenar os caracteres unicos
    int left = 0, maxLength = 0; // ponteiros e comprimento maximo
    for (int right = 0; right <s.size(); right++) { // percorre cada caractere da string
        while (chars.find(s[right]) != chars.end()) { // se o caractere ja existe, move a
            // Remove ate sumir a repeticao
            chars.erase(s[left]); // remove o caractere da esquerda
            left++; // move o ponteiro esquerdo
        }
        chars.insert(s[right]); // adiciona o caractere atual no conjunto
        maxLength = max(maxLength, right - left + 1); // calcula a largura da janela
    }
    return maxLength; // retorna o comprimento da maior substring unica
}
