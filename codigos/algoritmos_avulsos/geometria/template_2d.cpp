#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof ((c).begin ()) i=(c).begin (); i!=( c).end(); ++i)
#define ALL(c) (c).begin (), (c).end()

using namespace std;

const double PI = 2* acos (0);
const double EPS = 1e -10;

// Função de Comparação segura para doubles
inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol <y) ? -1 : 0 : 1;
}

// Estrutura de dados para Ponto ou Vetor
struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}

    point operator +( point q) const { return point(x + q.x, y + q.y); }
    point operator -( point q) const { return point(x - q.x, y - q.y); }
    point operator *( double t) const { return point(x * t, y * t ); }
    point operator /( double t) const { return point(x / t, y / t ); }
    double operator *( point q) const { return x * q.x + y * q.y; } // Produto Escalar (dot)
    double operator %( point q) const { return x * q.y - y * q.x; } // Produto Vetorial (cross)

    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==( point q) const { return cmp(q) == 0; }
    bool operator !=( point q) const { return cmp(q) != 0; }
    bool operator <( point q) const { return cmp(q) <0; }

    friend ostream& operator <<( ostream& o, point p) {
        return o <<"(" <<p.x <<", " <<p.y <<")";
    }
    static point pivot;
};
point point :: pivot;

double abs(point p) { return hypot(p.x, p.y); } // Magnitude do vetor
double arg(point p) { return atan2(p.y, p.x); } // Ângulo em radianos

// --- Funções Geométricas Primitivas ---

// Testa a orientação de 3 pontos.
// Pense em uma caminhada do ponto ’p’ para o ponto ’q ’.A funç ão
// determina de que lado o ponto ’r’ está em relação a essa trajetória.
// Retorna:
// +1: ’r’ está à esquerda da linha orientada p->q (curva anti -horária)
// -1: ’r’ está à direita da linha orientada p->q (curva horá ria)
// 0: ’r’, ’p’ e ’q’ são colineares (estão na mesma linha)
int ccw(point p, point q, point r) {
    return cmp((q - p) % (r - p));
}

// Verifica se o ponto p está no segmento de reta [a, b]
// Pré-condição: a, b, e p devem ser colineares.bool on_segment(point p, point a, point b) {
    return cmp((a - p) * (b - p)) <= 0;
}

// Interseção de Segmentos de Reta
// Verifica se o segmento [a,b] cruza com o segmento [c,d]
bool intersect(point a, point b, point c, point d) {
    int o1 = ccw(c, d, a), o2 = ccw(c, d, b);
    int o3 = ccw(a, b, c), o4 = ccw(a, b, d);
    if (o1 * o2 <0 && o3 * o4 <0) return true;
    if (on_segment(a, c, d) && o1 == 0) return true;
    if (on_segment(b, c, d) && o2 == 0) return true;
    if (on_segment(c, a, b) && o3 == 0) return true;
    if (on_segment(d, a, b) && o4 == 0) return true;
    return false;
}

// Distância de um ponto ’p’ a um segmento de reta [a, b]
double dist_point_segment (point p, point a, point b) {
    if (cmp((p - a) * (b - a)) <= 0) return abs(p - a);
    if (cmp((p - b) * (a - b)) <= 0) return abs(p - b);
    return fabs ((b - a) % (p - a)) / abs(b - a);
}

// calculando area triangulo com 3 pontos
double area_triangulo (point p, point q, point r) {
    return fabs ((q - p) % (r - p)) / 2.0;
}

// --- Funções para Polígonos ---
using polygon = vector<point >;
// adicionar o poligono que ta embaixo na função da area;
// Verifica se um ponto está dentro , na borda ou fora de um pol ígono.
// Retorna: 2 se DENTRO , 1 se NA BORDA , 0 se FORA.int ponto_em_poligono (const polygon& poly , point p) {
    if (poly.size () <3) return 0; // Não é um polígono válido

    double total_angle = 0;
    int n = poly.size ();

    for (int i = 0; i <n; i++) {
        point p1 = poly[i];
        point p2 = poly [(i + 1) % n];

        // Primeiro , verifica se o ponto está sobre a aresta atual
        if (ccw(p1 , p2 , p) == 0 && on_segment(p, p1 , p2)) {
            return 1; // NA BORDA
        }

        // Soma o ângulo sinalizado formado por p e a aresta p1 -p2
        total_angle += atan2 ((p1 - p) % (p2 - p), (p1 - p) * ( p2 - p));
    }

    // Compara o valor absoluto do ângulo total com PI.
    // Se for próximo de 2*PI , está dentro.Se for próximo de 0, está fora.
    // cmp(abs(total_angle), PI) > 0 verifica se |total_angle| > PI.return cmp(abs(total_angle), PI) > 0 ? 2 : 0;
}


// --- Estrutura para Retas (ax + by + c = 0) ---

struct Reta {
    double a, b, c;

    // Construtor a partir de dois pontos
    Reta(point p, point q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p % q;
    }

    // Avalia a equação da reta para um ponto p (eval(p) == 0 quer dizer que ta na reta o ponto)
    double eval(point p) const { return a * p.x + b * p.y + c; }

    // Distância de um ponto p à reta (infinita)
    double dist(point p) const { return fabs(eval(p)) / hypot(a , b); }

    // Retorna uma reta perpendicular que passa por p
    Reta perpendicular (point p) const {
        return Reta(-b, a, b * p.x - a * p.y);
    }

    // --- Operadores ---

    // Verifica se esta reta é paralela à reta ’r’
    bool operator ||( const Reta& r) const {
        return cmp(a * r.b - b * r.a) == 0;
    }

    // Verifica se esta reta é igual (coincidente) à reta ’r’
    bool operator ==( const Reta& r) const {
        return (* this || r) && cmp(a * r.c - c * r.a) == 0 && cmp(b * r.c - c * r.b) == 0;
    }

    // Retorna o ponto de interseção com a reta ’r’
    // PRECONDIÇÃO: As retas NÃO devem ser paralelas (verifique com || antes).point operator ^( const Reta& r) const {
        double det = a * r.b - b * r.a;
        return point ((b * r.c - c * r.b) / det , (c * r.a - a * r.c) / det);
    }

    private:
    // Construtor privado para uso interno (ex: no método perpendicular )
    Reta(double a, double b, double c) : a(a), b(b), c(c) {}
};


// --- Estrutura para Círculos ---

struct Circle {
    point o;
    long double r;

    Circle () {}
    Circle(point _o , long double _r) : o(_o), r(_r) {}

    // Círculo cujo diâmetro é o segmento AB
    Circle(point a, point b) {
        o = (a + b) / 2.0;
        r = abs(o - a);
    }

    // Círculo que passa por três pontos (circuncírculo do triâ ngulo ABC)
    Circle(point a, point b, point c) {
        // Encontra o ponto de interseção das mediatrizes de AB e BC
        Reta ab(a, b);
        Reta bc(b, c);
        Reta mediatriz_ab = ab.perpendicular ((a + b) / 2.0);
        Reta mediatriz_bc = bc.perpendicular ((b + c) / 2.0);

        // Se as mediatrizes forem paralelas , os pontos são colineares
        if (mediatriz_ab || mediatriz_bc) {
            o = point(HUGE_VAL , HUGE_VAL); // Ponto inválido
            r = -1.0; // Raio inválido
        } else {
            o = mediatriz_ab ^ mediatriz_bc ;
            r = abs(o - a);
        }
    }

    // Verifica se o ponto p está dentro ou na borda do círculo
    bool contains(point p) const {
        return cmp(abs(o - p), r) <= 0;
    }

    // Calcula a área da interseção com outro círculo ’c’
    long double getIntersectionArea (const Circle& c) const {
        long double d = abs(o - c.o);

        // Caso 1: Círculos não se tocam ou se tocam em apenas um ponto
        if (cmp(d, r + c.r) >= 0) {
            return
        }
        // Caso 2: Um círculo contém o outro
        if (cmp(d, abs(r - c.r)) <= 0) {
            long double min_r = min(r, c.r);
            return PI * min_r * min_r;
        }

        // Caso 3: Sobreposição parcial
        // A área é a soma das áreas de dois segmentos circulares.
        // Usamos a Lei dos Cossenos para encontrar os ângulos dos setores.long double angulo1 = acos ((d*d + r*r - c.r*c.r) / (2*d *r));
        long double angulo2 = acos ((d*d + c.r*c.r - r*r) / (2*d *c.r));

        // Área do setor - Área do triângulo = Área do segmento
        long double area_segmento1 = r*r * (angulo1 - 0.5 * sin (2* angulo1));
        long double area_segmento2 = c.r*c.r * (angulo2 - 0.5 * sin (2* angulo2));

        return area_segmento1 + area_segmento2 ;
    }
};
