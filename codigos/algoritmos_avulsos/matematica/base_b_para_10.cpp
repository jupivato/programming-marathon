#include <bits/stdc++.h>

using namespace std;

// Converte uma string ’num’ na base ’b’ para a base 10 ( decimal).long long to_decimal(const string& num , int b) {
    long long result = 0;
    long long power = 1;

    // Itera pela string da direita para a esquerda.for (int i = num.length () - 1; i >= 0; i--) {
        int digit_value;
        if (num[i] >= ’0’ && num[i] <= ’9’) {
            digit_value = num[i] - ’0’;
        } else {
            digit_value = num[i] - ’A’ + 10;
        }

        if (digit_value >= b) {
            // Dígito inválido para a base fornecida.
            // Você pode tratar o erro aqui (ex: retornar -1).return -1;
        }

        result += digit_value * power;
        power *= b;
    }
    return result;
}
