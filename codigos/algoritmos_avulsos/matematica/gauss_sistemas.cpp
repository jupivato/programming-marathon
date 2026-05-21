#include <bits/stdc++.h>
#define NMAX 20
using namespace std;
// matriz ampliada de coeficientes
double mat[NMAX][NMAX+1]; // armazena a matriz ampliada (coeficientes + resultados)
double sol[NMAX]; // armazena as soluções do sistema linear
void elimination(int n){
    double factor;
    for (int i = 0; i <n - 1; i++){
        for (int j = i+1; j <n; j++){
            factor = mat[j][i]/mat[i][i]; // calcula o fator de eliminação
            for (int k = 0; k <n + 1; k++){
                mat[j][k] = mat[j][k] - factor*mat[i][k]; // elimina os elementos abaixo da
            }
        }
    }
}
void solve(int n){
    memset(sol, 0, sizeof(sol)); // inicializa as soluções como zero
    double s = 0;
    for (int l = n - 1; l >= 0; l--) {
        s = 0;
        for (int j = l; j <n; j++) {
            s += sol[j]*mat[l][j]; // calcula a soma dos termos já resolvidos
        }
        sol[l] = (mat[l][n] - s) / mat[l][l]; // resolve a variável atual
    }
}
