#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    // begin() = ponteiro para o primeiro elemento
    // end()   = "depois do ultimo" (NAO aponta para o ultimo!)
    auto it = v.begin();
    cout << *it << "\n";   // 10
    it++;                  // avanca para o proximo
    cout << *it << "\n";   // 20

    // Percorrer do inicio ate (antes de) end
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    // Distancia entre iteradores (quantos passos)
    auto a = v.begin();
    auto b = v.end();
    cout << (b - a) << "\n";  // 4 = size()

    // Em vetor ORDENADO, lower_bound devolve iterator
    sort(v.begin(), v.end());
    auto pos = lower_bound(v.begin(), v.end(), 25);
    // pos aponta para o primeiro elemento >= 25
    if (pos != v.end())
        cout << "achou ou passou: " << *pos << "\n";

    return 0;
}
