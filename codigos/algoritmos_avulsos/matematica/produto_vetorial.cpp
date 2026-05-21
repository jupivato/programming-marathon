#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x1, y1, x2, y2, x3, y3, xv, yv;
    cin>> x1>> y1; // le as coordenadas do primeiro vertice do triangulo
    cin>> x2>> y2; // le as coordenadas do segundo vertice do triangulo
    cin>> x3>> y3; // le as coordenadas do terceiro vertice do triangulo
    cin>> xv>> yv; // le as coordenadas do ponto a ser verificado
    double c1 = (x2 - x1)*(yv - y1) - (y2 - y1)*(xv - x1); // calcula o produto cruzado para o
    double c2 = (x3 - x2)*(yv - y2) - (y3 - y2)*(xv - x2); // calcula o produto cruzado para o
    double c3 = (x1 - x3)*(yv - y3) - (y1 - y3)*(xv - x3); // calcula o produto cruzado para o
    // verifica se o ponto esta dentro do triangulo (se todos os produtos cruzados sao positivos ou negativos)
    if ((c1 >= 0 && c2 >= 0 && c3 >= 0) || (c1 <= 0 && c2 <= 0 && c3 <= 0)) {
        cout <<"Dentro do triangulo" <<endl; // ponto esta dentro do triangulo
    } else {
        cout <<"Fora do triangulo" <<endl; // ponto esta fora do triangulo
    }
    return 0;
}
