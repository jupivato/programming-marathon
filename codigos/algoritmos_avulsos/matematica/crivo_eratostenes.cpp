#include <bits/stdc++.h>

using namespace std;

// Define o limite máximo para o crivo.
// Em problemas , ajuste para o maior valor necessário.const int MAXN = 1000001;

// Vetor booleano global para armazenar a primalidade.
// is_prime[i] = true se i for primo , false caso contrário.vector<bool > is_prime(MAXN , true);

// Função que implementa o Crivo de Eratóstenes.
// Preenche o vetor is_prime em O(N log log N).void sieve () {
    // 1.Marcar 0 e 1 como não-primos
    is_prime [0] = is_prime [1] = false;

    // 2.Iterar a partir de p=2
    // A iteração vai até p*p <MAXN , pois qualquer número composto
    // n terá um fator primo <= sqrt(n).for (int p = 2; p * p <MAXN; p++) {
        // 3.Se p ainda não foi marcado , ele é primo
        if (is_prime[p]) {
            // 4.Marca todos os múltiplos de p como não-primos
            // Otimização: começamos a marcar de p*p, pois os m últiplos
            // menores (2*p, 3*p, etc.) já foram marcados por primos menores.for (int i = p * p; i <MAXN; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

// Exemplo de uso
int main () {
    // Pré-computa todos os primos até MAXN.
    // Chame esta função uma vez no início do seu código.sieve ();

    // Agora , verificar se um número é primo é uma consulta O (1).cout <<"37 eh primo? " <<(is_prime [37] ? "Sim" : "Nao") <<endl;
    cout <<"100 eh primo? " <<(is_prime [100] ? "Sim" : "Nao") <<endl;

    // O código da imagem lia A e B e contava os primos no intervalo.
    // Com o crivo , isso se torna trivial:
    int A = 1, B = 100;
    int count = 0;
    for (int i = A; i <= B; ++i) {
        if (is_prime[i]) {
            count ++;
        }
    }
    cout <<"Existem " <<count <<" primos entre " <<A <<" e " <<B <<"." <<endl;

    return 0;
}
