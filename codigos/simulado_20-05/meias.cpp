#include<bits/stdc++.h>

using namespace std;

// Estrutura para guardar as meias de cada lado para um tipo específico
struct Meia {
    long long direita = 0;
    long long esquerda = 0;
    long long qualquer = 0;
};

int main() {
    // Otimização de leitura/escrita para maratona de programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // O mapa associa QUALQUER string (nome do tipo) à sua contagem de lados
    map<string, Meia> gaveta;

    // 1. Leitura das n linhas e agrupamento
    for (int i = 0; i < n; ++i) {
        string tipo, lado;
        long long qtd;
        cin >> tipo >> lado >> qtd;

        // Verifica o lado (ajuste as strings se o problema usar "direito" ou "D")
        if (lado == "direito" || lado == "direita" || lado == "D") {
            gaveta[tipo].direita += qtd;
        } else if (lado == "esquerdo" || lado == "esquerda" || lado == "E") {
            gaveta[tipo].esquerda += qtd;
        } else { 
            // "qualquer", "qualquer_um", "Q", etc.
            gaveta[tipo].qualquer += qtd;
        }
    }

    long long total_azar = 0;

    // 2. Análise do pior cenário para cada tipo de meia mapeado
    for (auto const& [tipo, info] : gaveta) {
        long long d = info.direita;
        long long e = info.esquerda;
        long long q = info.qualquer;

        // Um tipo só consegue formar par se:
        // - Tiver pelo menos uma direita E uma esquerda OU
        // - Tiver meias "qualquer" que somadas às outras deem pelo menos 2 meias no total
        bool pode_formar_par = (d > 0 && e > 0) || (q > 0 && (q + d + e >= 2));

        if (!pode_formar_par) {
            // Se NÃO dá para formar par (ex: 10 meias "esportiva" esquerdas),
            // o azarado pode puxar TODAS elas da gaveta sem fazer nenhum par.
            total_azar += (d + e + q);
        } else {
            // Se DÁ para formar par, pegamos o máximo possível de meias sem fechar o par:
            // Pegamos todas do lado majoritário + 1 curinga (se houver)
            long long max_lados = max(d, e);
            long long tem_curinga = (q > 0) ? 1 : 0;
            
            total_azar += max_lados + tem_curinga;
        }
    }

    // A próxima meia tirada (total_azar + 1) garante o primeiro par
    cout << total_azar + 1 << "\n";

    return 0;
}