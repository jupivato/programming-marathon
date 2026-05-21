#include <bits/stdc++.h>
using namespace std;

// Pré-requisito: Template Básico de Geometria 2D com a struct ’point ’.

// --- Par de Pontos Mais Próximo ---

// Função auxiliar para calcular a distância ao quadrado.Strings
// Evitar o uso de sqrt () até o final torna o código mais rá pido e preciso.double distSq(point p1 , point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// Função de força bruta para os casos base da recursão
double closest_brute_force (const vector<point >& pts) {
    double min_dist_sq = DBL_MAX; // DBL_MAX está em <cfloat >
    for (int i = 0; i <pts.size (); ++i) {
        for (int j = i + 1; j <pts.size (); ++j) {
            min_dist_sq = min(min_dist_sq , distSq(pts[i], pts[j ]));
        }
    }
    return min_dist_sq;
}

// Função recursiva principal
double closest_pair_recursive (vector<point >& pts_sorted_by_x ) {
    int n = pts_sorted_by_x .size ();

    // 1.Caso base: se há poucos pontos , usa força bruta.if (n <= 3) {
        return closest_brute_force ( pts_sorted_by_x );
    }

    // 2.Dividir
    int mid = n / 2;
    point mid_point = pts_sorted_by_x [mid];

    // Cria os subconjuntos esquerdo e direito
    vector<point > left_half , right_half;
    for (int i = 0; i <mid; ++i) left_half.push_back( pts_sorted_by_x [i]);
    for (int i = mid; i <n; ++i) right_half.push_back( pts_sorted_by_x [i]);

    // 3.Conquistar: chama recursivamente
    double dl_sq = closest_pair_recursive (left_half);
    double dr_sq = closest_pair_recursive (right_half);
    double min_dist_sq = min(dl_sq , dr_sq);

    // 4.Combinar: verificar pares na faixa central
    vector<point > strip;
    for (const auto& p : pts_sorted_by_x ) {
        // Adiciona pontos que estão na faixa de largura 2*d da linha central
        if (pow(p.x - mid_point.x, 2) <min_dist_sq) {
            strip.push_back(p);
        }
    }

    // Ordena a faixa pela coordenada Y.Este sort é o gargalo para O(N log^2 N).sort(strip.begin (), strip.end(), []( point a, point b){ return a.y <b.y; });

    // Verifica os pares dentro da faixa
    for (int i = 0; i <strip.size (); ++i) {
        // A otimização chave: para cada ponto , só precisamos verificar
        // um número constante de vizinhos próximos no eixo Y.for (int j = i + 1; j <strip.size () && pow(strip[j].y - strip[i].y, 2) <min_dist_sq; ++j) {
            min_dist_sq = min(min_dist_sq , distSq(strip[i], strip[j]));
        }
    }

    return min_dist_sq;
}

// Função principal que o usuário chama
double closest_pair(vector<point >& pts) {
    if (pts.size () <2) return DBL_MAX;

    // Passo de pré-processamento: ordenar todos os pontos por X
    sort(pts.begin (), pts.end(), []( point a, point b){ return a .x <b.x; });

    // A função recursiva retorna a distância ao quadrado , entã o tiramos a raiz no final.return sqrt( closest_pair_recursive (pts));
}
