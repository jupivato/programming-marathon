#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, char ori, char aux, char des){

    if (n == 1) {
        cout << ori << " -> " << des << endl;
        return;
    }

    hanoi(n-1, ori, des, aux);
    hanoi(1, ori, aux, des);
    hanoi(n-1, aux, ori, des);
}

int main() {

    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');

  return 0;
}
