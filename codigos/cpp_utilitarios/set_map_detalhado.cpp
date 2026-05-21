#include <bits/stdc++.h>
using namespace std;

int main() {
    // SET: guarda valores UNICOS, sempre em ORDEM crescente
    set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(10);   // repetido: ignorado
    // s internamente: {10, 30}

    // Acessar: NAO existe s[i]! Use iterador ou find
    if (s.count(10)) { }           // 1 se existe, 0 se nao
    auto it = s.find(10);            // iterator para 10, ou s.end() se nao tem
    if (it != s.end())
        cout << *it << "\n";         // desreferencia o iterator

    // Percorrer em ordem (ja vem ordenado)
    for (int x : s)
        cout << x << " ";            // imprime 10 depois 30

    // Primeiro elemento >= 25
    auto lb = s.lower_bound(25);     // aponta para 30

    s.erase(10);                     // apaga o valor 10

    // MAP: cada CHAVE aparece no maximo uma vez; par (chave, valor)
    map<string, int> freq;
    freq["uva"] = 3;                 // cria ou sobrescreve
    freq["uva"]++;                   // incrementa o valor da chave "uva"

    // CUIDADO: freq["banana"] cria entrada com 0 se nao existia!
    if (freq.count("banana"))        // teste antes se so quer consultar
        cout << freq["banana"];

    for (auto& p : freq)
        cout << p.first << " -> " << p.second << "\n";

    // MULTISET: permite repetidos, ainda ordenado
    multiset<int> ms = {5, 5, 1};
    ms.erase(ms.find(5));            // remove UMA copia de 5
    // ms.erase(5);                  // ERRADO: remove TODAS as copias de 5

    return 0;
}
