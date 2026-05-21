#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector<tuple<...>>: sort padrao compara lexicograficamente
    // campo 0; empate -> campo 1; empate -> campo 2; ...
    vector<tuple<int, int, string>> eventos = {
        make_tuple(5, 1, "B"),
        make_tuple(3, 2, "A"),
        make_tuple(3, 1, "C"),
        make_tuple(5, 0, "D"),
    };
    sort(eventos.begin(), eventos.end());
    // ordem: (3,1,C), (3,2,A), (5,0,D), (5,1,B)
    //        ^t=3      ^t=3 id=2   ^t=5 id=0  ^t=5 id=1

    // Percorrer depois do sort
    for (auto& e : eventos) {
        int t = get<0>(e);
        int id = get<1>(e);
        string nome = get<2>(e);
        cout << t << " " << id << " " << nome << "\n";
    }

    // Ordenar tupla por UM campo especifico (ex.: so pelo tempo t)
    sort(eventos.begin(), eventos.end(),
        [](const tuple<int, int, string>& a, const tuple<int, int, string>& b) {
            return get<0>(a) < get<0>(b);
        });

    // Ordenar por t crescente, desempate por id DECRESCENTE
    sort(eventos.begin(), eventos.end(),
        [](const tuple<int, int, string>& a, const tuple<int, int, string>& b) {
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            return get<1>(a) > get<1>(b);
        });

    // Tupla com tipos mistos: (distancia, vertice, flag)
    vector<tuple<int, int, bool>> fila;
    fila.push_back(make_tuple(10, 3, true));
    fila.push_back(make_tuple(2, 7, false));
    sort(fila.begin(), fila.end());  // menor distancia primeiro

    return 0;
}
