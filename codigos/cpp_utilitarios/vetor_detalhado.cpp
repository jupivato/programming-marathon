#include <bits/stdc++.h>
using namespace std;

int main() {
    // --- CRIAR ---
    vector<int> v;              // vazio
    vector<int> a(5);           // cinco int (valor 0)
    vector<int> b(5, 7);        // cinco vezes o numero 7
    vector<int> c = {3, 1, 4};  // lista inicial

    // --- ACESSAR (indices comecam em 0, como array) ---
    c[0] = 10;                  // le e escreve na posicao 0
    int x = c.at(1);            // igual c[1], mas checa limite (mais lento)
    int primeiro = c.front();   // c[0]
    int ultimo = c.back();      // c[c.size()-1]

    // --- TAMANHO ---
    int n = c.size();           // quantos elementos tem AGORA
    bool vazio = c.empty();     // true se size() == 0

    // --- MODIFICAR no final (mais comum) ---
    c.push_back(5);             // coloca 5 no final
    c.pop_back();               // remove o ultimo (nao retorna o valor!)

    c.resize(10);               // novo tamanho; novas posicoes viram 0
    c.clear();                  // size() vira 0

    // --- PERCORRER ---
    for (int i = 0; i < (int)c.size(); i++)
        cout << c[i] << " ";

    for (int valor : c)        // copia cada elemento (nao altera c)
        cout << valor << " ";

    for (int& valor : c)       // referencia: altera o proprio vetor
        valor *= 2;

    // --- VETOR DE VETORES (grafo, matriz esparsa) ---
    int nos = 4;
    vector<vector<int>> adj(nos);  // adj[0], adj[1], ... listas vazias
    adj[0].push_back(1);
    adj[0].push_back(2);

    return 0;
}
