#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Função auxiliar para normalizar e arredondar a longitude para o índice do vetor (0 a 360)
int obter_indice_meridiano(double longitude) {
    // Arredonda para o inteiro mais próximo
    int lon_int = round(longitude);
    
    // Garante que -180 e 180 apontem para o mesmo lugar físico na esfera (índice 180)
    if (lon_int == -180) lon_int = 180;
    
    // Mapeia de [-180, 179] para [0, 359] mudando o referencial
    return lon_int + 180; 
}

int main() {
    // Otimização de I/O para maratona
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<double> lats(n), longs(n);
    for (int i = 0; i < n; ++i) {
        cin >> lats[i] >> longs[i];
    }

    if (n < 2) {
        cout << "NAO\n";
        return 0;
    }

    // Vetor que representa os 360 meridianos da Terra (índices de 0 a 359)
    // 0 = não visitado, 1 = visitado
    vector<int> visitado(360, 0);

    // Marca a posição inicial do circuito
    int atual = obter_indice_meridiano(longs[0]);
    visitado[atual] = 1;

    bool valido = true;

    // Vamos processar todos os passos, incluindo a volta do último ponto para o primeiro
    for (int i = 1; i <= n; ++i) {
        // Se i == n, estamos fechando o circuito voltando para o ponto inicial (longs[0])
        int destino = obter_indice_meridiano(longs[i % n]);

        if (atual == destino) {
            // Se a pessoa não saiu do lugar em coordenadas inteiras, apenas continua
            continue;
        }

        // Descobre a distância indo por um lado e pelo outro para pegar o menor caminho
        int dist_direta = (destino - atual + 360) % 360;
        int dist_indireta = (atual - destino + 360) % 360;

        int passo = 0;
        int passos_para_dar = 0;

        if (dist_direta < dist_indireta) {
            passo = 1; // Movimento para a "direita" (Leste)
            passes_para_dar = dist_direta;
        } else {
            passo = -1; // Movimento para a "esquerda" (Oeste)
            passos_para_dar = dist_indireta;
        }

        // Caminha preenchendo as casas no vetor entre o ponto atual e o destino
        for (int p = 0; p < passos_para_dar; ++p) {
            atual = (atual + passo + 360) % 360;

            // Se estamos no meio do caminho e tentamos pisar em uma casa já visitada:
            // EXCEÇÃO: Se for o último passo do circuito (i == n) e chegamos exatamente 
            // na casa inicial, isso é permitido (o círculo fechou perfeitamente).
            if (visitado[atual] == 1) {
                if (i == n && atual == obter_indice_meridiano(longs[0])) {
                    // Fechamento válido da volta completa
                    continue;
                }
                valido = false;
                break;
            }

            // Marca a casa como coberta
            visitado[atual] = 1;
        }

        if (!valido) break;
    }

    // Para passar em TODOS os meridianos, o vetor inteiro deve estar marcado com 1
    if (valido) {
        for (int i = 0; i < 360; ++i) {
            if (visitado[i] == 0) {
                valido = false;
                break;
            }
        }
    }

    if (valido) {
        cout << "SIM\n";
    } else {
        cout << "NAO\n";
    }

    return 0;
}