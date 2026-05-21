#include <bits/stdc++.h>
using namespace std;

int main() {
    // set: elementos unicos, ordenados - O(log n) inserir/buscar
    set<int> s = {3, 1, 2};
    s.insert(2);              // duplicata ignorada
    if (s.count(1)) cout << "tem 1\n";
    s.erase(1);
    auto it = s.lower_bound(2);  // primeiro >= 2

    // multiset: permite repetidos
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.erase(ms.find(1));     // apaga UMA ocorrência de 1
    cout << ms.count(1) << "\n";

    // map: chave -> valor, chaves ordenadas
    map<string, int> idade;
    idade["ana"] = 20;
    idade["bob"]++;
    if (idade.count("ana"))
        cout << idade["ana"] << "\n";

    for (auto& par : idade)
        cout << par.first << " " << par.second << "\n";

    // unordered_map / unordered_set: média O(1), sem ordem
    unordered_map<int, int> cnt;
    cnt[42]++;

    return 0;
}
