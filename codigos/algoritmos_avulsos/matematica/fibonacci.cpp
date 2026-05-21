#include <vector >

// Fibonacci com Exponenciação de Matriz - O(log n)
// Ideal para N grande e com resultado modular.

// Define um tipo ’matrix ’ para facilitar a leitura do código.using matrix = std::vector<std::vector<long long>>;

// Define o módulo para os cálculos.Mude se o problema pedir outro.const int MOD = 1e9 + 7;

// Função para multiplicar duas matrizes 2x2 sob um módulo.matrix multiply(const matrix& A, const matrix& B) {
    matrix C = {{0, 0}, {0, 0}};
    for (int i = 0; i <2; i++) {
        for (int j = 0; j <2; j++) {
            for (int k = 0; k <2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Função para elevar uma matriz a uma potência (exponenciação rápida).matrix matrix_pow(matrix A, long long p) {
    matrix res = {{1, 0}, {0, 1}}; // Matriz identidade

    while (p > 0) {
        if (p & 1) { // Se p for ímpar
            res = multiply(res , A);
        }
        A = multiply(A, A);
        p>>= 1; // p = p / 2
    }
    return res;
}

// Função principal para encontrar o N-ésimo número de Fibonacci.long long fib(long long n) {
    if (n == 0) {
        return 0;
    }

    // Matriz de transformação de Fibonacci.matrix T = {{1, 1}, {1, 0}};

    // Calcula T^n.De acordo com a fórmula , o resultado F(n)
    // estará na posição [0][1] da matriz resultante.T = matrix_pow(T, n);

    return T[0][1];
}

/*
// Exemplo de uso na main:
int main () {
    long long n;
    std::cin>> n;
    std:: cout <<fib(n) <<std:: endl;
    return 0;
}
*/
