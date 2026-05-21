#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcabc";
    cout << (int)s.size() << " " << s[0] << "\n";
    s += "d";
    reverse(s.begin(), s.end());

    // Substring: s.substr(pos, tamanho) - omitir tamanho = ate o fim
    string sub = s.substr(1, 3);

    // stringstream: parsear linha com vários números
    string linha = "10 20 30";
    stringstream ss(linha);
    int x;
    while (ss >> x) cout << x << " ";
    cout << "\n";

    // bitset: máscaras e DP em bitmask (até ~64 ou ~1024 bits)
    bitset<32> b(5);       // binário de 5
    b.set(3);
    b.flip(0);
    cout << b.count() << " " << b.test(2) << "\n";
    int mask = (int)b.to_ulong();

    // Operações comuns em maratona
    cout << (1 << 10) << "\n";           // 2^10
    cout << __builtin_popcount(7) << "\n";  // bits 1 em 7 (GCC)

    return 0;
}
