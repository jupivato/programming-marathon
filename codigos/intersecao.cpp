#include <bits/stdc++.h>

using namespace std;

struct Ponto { double x, y; };

struct Segmento 
{
  int id;
  Ponto esq, dir; // esq = ponta esquerda (início), dir = ponta direita (fim)
};

// varre o gráfico da esquerda para a direita
double X_ATUAL;

// diz se vira para esquerda ou para direita
bool faz_curva_esquerda(Ponto a, Ponto b, Ponto c) 
{
  double det = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
  return det > 0;
}

// verifica se dois segmentos se cruzam
bool cruzam(Segmento s1, Segmento s2) 
{
  return (faz_curva_esquerda(s1.esq, s1.dir, s2.esq) != faz_curva_esquerda(s1.esq, s1.dir, s2.dir)) &&
         (faz_curva_esquerda(s2.esq, s2.dir, s1.esq) != faz_curva_esquerda(s2.esq, s2.dir, s1.dir));
}

// altura y do segmento na posição x atual
double calcular_Y_no_X_atual(const Segmento& s) 
{
  if (s.esq.x == s.dir.x) return s.esq.y; // evita divisão por zero se for reta vertical
  double proporcao = (X_ATUAL - s.esq.x) / (s.dir.x - s.esq.x);
  return s.esq.y + proporcao * (s.dir.y - s.esq.y);
}

// ordena os segmentos de baixo pra cima
struct RadarOrdenaPorY {
  bool operator()(const Segmento& a, const Segmento& b) const 
  {
    if (a.id == b.id) return false;
    
    double y_a = calcular_Y_no_X_atual(a);
    double y_b = calcular_Y_no_X_atual(b);
    
    if (abs(y_a - y_b) > 1e-9) return y_a < y_b;
    
    return a.id < b.id; // desempate pelo ID
  }
};

struct Evento 
{
  double x;      // em qual 'X' o evento acontece
  int tipo;      // 1 = inicio, -1 = fim
  int seg_id;    // qual é o segmento dono desse evento

  // ordena os eventos da esquerda pra direita (menor X pro maior X)
    bool operator<(const Evento& outro) const {
      if (x != outro.x) return x < outro.x;
      return tipo > outro.tipo; // se empatar no X, processa quem inicia antes de quem termina
  }
};

// algoritmo
bool varredura_shamos_hoey(vector<Segmento>& segmentos) 
{
  vector<Evento> agenda;

  for (int i = 0; i < segmentos.size(); ++i) 
  {
    // garante que o ponto 'esq' é sempre o menor X
    if (segmentos[i].esq.x > segmentos[i].dir.x) swap(segmentos[i].esq, segmentos[i].dir);
    agenda.push_back({segmentos[i].esq.x, 1, i});  // inicio
    agenda.push_back({segmentos[i].dir.x, -1, i}); // fim
  }

  // organiza a agenda da esquerda pra direita
  sort(agenda.begin(), agenda.end());

  // guarda os segmentos ativos, ordenados por Y automaticamente
  set<Segmento, RadarOrdenaPorY> radar;

  // processando a agenda
  for (auto& evento : agenda) 
  {
    X_ATUAL = evento.x; // a linha de varredura anda até esse X
    int id = evento.seg_id;

    if (evento.tipo == 1) 
    { 
      // inicio de um segmento
      // coloca no radar
      auto it = radar.insert(segmentos[id]).first; 

      // olha quem está acima e abaixo dele no radar
      auto vizinho_acima = next(it);
      auto vizinho_abaixo = (it == radar.begin()) ? radar.end() : prev(it);

      // testa cruzamento SÓ com os vizinhos
      if (vizinho_acima != radar.end())
      if (cruzam(*it, *vizinho_acima)) return true;
      if (vizinho_abaixo != radar.end())
      if (cruzam(*it, *vizinho_abaixo)) return true;
    } 
    else 
    { 
      // fim de um segmento
      auto it = radar.find(segmentos[id]);
      if (it != radar.end()) 
      {
        // antes de tirar ele do radar, olha os vizinhos dele
        auto vizinho_acima = next(it);
        auto vizinho_abaixo = (it == radar.begin()) ? radar.end() : prev(it);

        // o segmento do meio vai sumir, então o de cima e o de baixo vão virar vizinhos
        // testa se os novos vizinhos se cruzam
        if (vizinho_abaixo != radar.end() && vizinho_acima != radar.end())
        if (cruzam(*vizinho_abaixo, *vizinho_acima)) return true;

        // remove do radar
        radar.erase(it);
      }
    }
  }
  return false;
}

int main() {
  vector<Segmento> conj = {
    {1, {6, 3}, {8, 7}},
    {2, {2, 1}, {1, 3}},
    {3, {3, 4}, {2, 4}},
    {4, {0, 6}, {5, 8}},
    {5, {3, 5}, {7, 0}},
    {6, {4, 1}, {9, 2}}
  };

  cout << "Intersecao detectada? ";
  if (varredura_shamos_hoey(conj)) cout << "SIM" << endl;
  else cout << "NAO" << endl;

  return 0;
}
