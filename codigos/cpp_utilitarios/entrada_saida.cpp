#include <bits/stdc++.h>
using namespace std;

int main() {
    // Desliga sincronização com C e desliga flush automático do cin
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Saída com precisão fixa (útil em geometria)
    cout << fixed << setprecision(6);
    double x = 1.0 / 3.0;
    cout << x << "\n";

    // scanf / printf (ainda úteis em alguns juízes antigos)
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);

    // Ler linha inteira (cuidado: após cin>> pode sobrar '\n' no buffer)
    string linha;
    getline(cin, linha);

    return 0;
}
