#include <bits/stdc++.h>

using namespace std;

// Sliding Window Maximum - O(n)
// Encontra o valor máximo em cada janela de tamanho ’k ’.
// Retorna um vetor contendo o máximo de cada janela.
// O vetor de resultado terá ‘arr.size () - k + 1‘ elementos.vector<int > sliding_window_max (const vector<int >& arr , int k) {
    int n = arr.size ();
    vector<int > result;
    // O deque armazena pares {valor , índice} dos elementos da janela.deque<pair<int , int>> dq;

    for (int i = 0; i <n; ++i) {
        // 1.Remove da frente o elemento que já saiu da janela .
        // A janela atual tem os índices [i - k + 1, i].if (!dq.empty () && dq.front ().second <= i - k) {
            dq.pop_front ();
        }

        // 2.Remove da traseira os elementos menores ou iguais ao atual ,
        // pois eles nunca poderão ser o máximo enquanto o elemento atual
        // estiver na janela.while (!dq.empty () && dq.back ().first <= arr[i]) {
            dq.pop_back ();
        }

        // 3.Adiciona o elemento atual {valor , índice} na traseira.dq.push_back ({arr[i], i});

        // 4.Se a janela já está completa , o máximo é o da frente.
        // A primeira janela completa termina no índice k-1.if (i >= k - 1) {
            result.push_back(dq.front ().first);
        }
    }
    return result;
}
