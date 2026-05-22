#include <bits/stdc++.h>
using namespace std;

// vetor ORDENADO: existe par com soma target?
bool existeParComSoma(const vector<int>& a, int target) {
    int l = 0, r = (int)a.size() - 1;
    while (l < r) {
        long long s = (long long)a[l] + a[r];
        if (s == target) return true;
        if (s < target) l++;
        else r--;
    }
    return false;
}

// remove duplicatas de vetor ja ordenado (retorna novo tamanho)
int removerDuplicatasOrdenado(vector<int>& a) {
    if (a.empty()) return 0;
    int k = 1;
    for (int i = 1; i < (int)a.size(); i++)
        if (a[i] != a[k - 1])
            a[k++] = a[i];
    return k;
}

// mescla dois vetores ordenados em um terceiro (tamanho n+m)
void mergeOrdenados(const vector<int>& a, const vector<int>& b, vector<int>& out) {
    int i = 0, j = 0;
    out.clear();
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) out.push_back(a[i++]);
        else out.push_back(b[j++]);
    }
    while (i < (int)a.size()) out.push_back(a[i++]);
    while (j < (int)b.size()) out.push_back(b[j++]);
}
