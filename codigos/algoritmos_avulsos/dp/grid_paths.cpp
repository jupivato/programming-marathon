#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main ()
{
    int mat [1001][1001];
    vector<vector<int>> dp(1001 , vector<int >(1001 , 0));
    int h, w;
    cin>> h>> w;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char aux;
            cin>> aux;
            if(aux == ’.’) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    if(mat [0][0] == 1)dp [0][0] = 1;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(mat[i][j] == 1){
                if(i>0 && j>0){
                    dp[i][j] = (dp[i -1][j] + dp[i][j -1]) % MOD;
                }
                else if(i>0){
                    dp[i][j] = dp[i -1][j] % MOD;
                }else if(j>0){
                    dp[i][j] = dp[i][j-1] % MOD;
                }
            }
        }
    }
    cout <<dp[h -1][w-1] <<endl;
    return 0;
}
