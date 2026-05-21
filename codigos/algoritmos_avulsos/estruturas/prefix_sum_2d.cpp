#include <bits/stdc++.h>
using namespace std;

const int N=1123;
int prefix[N][N],vet[N][N];
void monta(int n,int m){
    memset(prefix ,0, sizeof(prefix));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) prefix[i][j]= prefix[i -1][j]+ prefix[i ][j-1]- prefix[i -1][j -1]+ vet[i -1][j -1]; Programação Dinâmica
    }
}

int soma(int x,int y,int lado){
    return prefix[x+lado ][y+lado]-prefix[x+lado ][y-1]- prefix[x -1][y+lado ]+ prefix[x -1][y -1];
}
