#include <bits/stdc++.h>

using namespace std;

bool dfs(int linha, int coluna, vector<string>& mapa, int M, int N) {
  // testa se está nos limites do tabuleiro
  if (linha < 0 || linha >= M || coluna < 0 || coluna >= N) return false;
  // achou o destino
  if (mapa[linha][coluna] == 'S') return true;
  // se nao pode passar ou já foi visitado
  if (mapa[linha][coluna] == 'X' || mapa[linha][coluna] == 'V') return false;

  // marca visitado
  mapa[linha][coluna] = 'V';
  
  // testa todas as direções via recursão
  if (dfs(linha + 1, coluna, mapa, M, N)) return true; // baixo
  if (dfs(linha - 1, coluna, mapa, M, N)) return true; // cima
  if (dfs(linha, coluna + 1, mapa, M, N)) return true; // direita
  if (dfs(linha, coluna - 1, mapa, M, N)) return true; // esquerda

  return false;
}

int main() {

  int m, n;

  while (cin >> m >> n)
  {
    vector<string> mapa(m);
    int inicioLinha = -1, inicioColuna = -1;
    
    for (int i = 0; i < m; ++i) 
    {
      cin >> mapa[i];
      for (int j = 0; j < n; ++j) 
      {
        if (mapa[i][j] == 'R') 
        {
            inicioLinha = i;
            inicioColuna = j;
        }
      }
    }
    
    if (dfs(inicioLinha, inicioColuna, mapa, m, n)) cout << "S\n"; // Possível
    else cout << "N\n"; // Impossível
  }
  return 0;
}
