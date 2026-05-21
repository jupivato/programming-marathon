#include <bits/stdc++.h>

using namespace std;

// Converte um número ’n’ da base 10 para uma base ’b’ (2 <= b <= 36).string from_decimal (long long n, int b) {
    if (n == 0) {
        return "0";
    }

    string result = "";
    while (n > 0) {
        int remainder = n % b;
        if (remainder <10) {
            // Converte o resto numérico para seu caractere ’0’-’9’
            result += to_string(remainder);
        } else {
            // Converte o resto numérico para seu caractere ’A ’-’Z’
            result += (char)(’A’ + (remainder - 10));
        }
        n /= b;
    }

    // Os restos foram coletados na ordem inversa , então revertemos a string.reverse(result.begin (), result.end());
    return result;
}
