#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, c;
    bool valido = true;

    cin >> n >> m >> c;

    int sala[n][m];
    int fileiras[m] = {};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> sala[i][j];
            cout << "verificando a posicao " << i << j << endl;
            if(sala[i][j])fileiras[j] = sala[i][j];
            // verifica cadeira da esquerda (se as duas forem > 0 = false)
            if(j > 0 && sala[i][j] && fileiras[j-1]) 
            {
              cout << "falhou no primeiro" << endl;
              valido = false;
            }
            // verifica cadeira de cima (se as duas forem > 0 = false)
            if(i > 0 && sala[i][j] && fileiras[i-1]) 
            {
              cout << "falhou no segundo" << endl;
              cout << sala[i][j] << endl;
              cout << fileiras[i-1] << endl;
              valido = false;
            }
            // conferindo pessoas na msm fileira com menos de c cadeiras de distancia e mesma provavalido = false;
            if(i >= c && c != 0){ 
              if (sala[i][j] && sala[i-c] && sala[i][j] == sala[i - c][j]) 
              {
                cout << "falhou no terceiro" << endl;
                valido = false;
              }
            }
            if (j >= c && c!= 0)
            {
              if (sala[i][j] && sala[i][j-c] && sala[i][j]== sala[i][j-c])
              {
                cout << "falhou no quarto" << endl;
                valido = false;
              }
            }
        }
    }

    if(!valido) cout << "N" << "\n";
    else cout << "S" << "\n";
    return 0;
}
