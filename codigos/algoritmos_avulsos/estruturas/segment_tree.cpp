#include <bits/stdc++.h>
using namespace std;
// range query multiplicacao
int vet[]; // vetor de valores para a árvore
struct tree{
    tree *esq, *dir; // ponteiros para os filhos esquerdo e direito
    int from, to, valor; // intervalo de indices e o valor do nó
    tree(int _from, int _to):from(_from), to(_to), dir(NULL), esq(NULL), valor(1){} //
};
// constrói a árvore de segmentação para multiplicação de intervalo
tree * build(int e, int d){
    if (e > d) return NULL; // caso base: intervalo inválido
    tree *res = new tree(e,d); // cria um nó para o intervalo
    if (e == d) res->valor = vet[e]; // valor de nó para elemento único
    else{
        int m = (e+d)/2; // encontra o meio do intervalo
        res->esq = build(e, m); res->dir = build(m+1, d); // cria filhos esquerdo e direito
        if (res->esq != NULL) res->valor *= res->esq->valor; // atualiza o valor com o produto
        if (res->dir != NULL) res->valor *= res->dir->valor; // atualiza o valor com o produto
    }
    return res;
}
// realiza a consulta para o produto de um intervalo
int query(tree *arv, int e, int d){
    if (arv == NULL) return 1; // caso base: intervalo vazio
    if (e <= arv->from && arv->to >= d) return arv->valor; // se o intervalo está completamente
    if (e > arv->to) return 1; if (d <arv->from) return 1; // se o intervalo não se sobrepõe
    // realiza a consulta recursiva nos filhos esquerdo e direito
    return query(arv->esq, e, d)*query(arv->dir, e, d);
}
// realiza a atualização de um valor no intervalo
int update(tree *arv, int i, int valor){
    if (arv == NULL) return 1; // caso base: nó vazio
    if (arv->to <i || arv->from > i) return arv->valor; // se o índice não está no intervalo
    if (arv->from == arv->to && arv->from == i) arv->valor = valor; // se o nó representa o í
    else arv->valor = (update(arv->esq, i, valor)*update(arv->dir, i, valor)); // atualiza
    return arv->valor;
}
int main()
{
    int a, b, ori, des, novo_valor;
    while (cin>> a>> b)
    {
        char aux;
        string res = "";
        for (int i = 0; i <a; i++)
        {
            int a;
            cin>> a;
            if (a > 0) vet[i] = 1;
            else if (a == 0) vet[i] = 0;
            else vet[i] = -1;
        }
        tree* arvore = build(0,a-1);
        while (b--)
        {
            cin>> aux;
            if (aux == ’C’)
            {
                cin>> ori>> novo_valor;
                if (novo_valor > 0) novo valor = 1;
                else if (novo_valor == 0) novo_valor = 0;
                else novo_valor = -1;
                update(arvore, ori-1, novo_valor);
            }
            else if (aux == ’P’)
            {
                cin>> ori>> des;
                int aux = query(arvore, ori-1, des-1);
                if (aux == 0)res += ’0’;
                else if (aux > 0) res+= ’+’;
                else res+= ’-’;
            }
        }
        cout <<res <<endl;
    }
    return 0;
}
