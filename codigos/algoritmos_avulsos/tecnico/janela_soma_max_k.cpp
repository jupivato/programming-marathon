#include <bits/stdc++.h>
using namespace std;
int maxSumSlidingWindow(const vector<int>& nums, int k) {
    int n = nums.size();
    if (n <k) return -1; // caso invalido, se a quantidade de elementos for menor que k
    int maxSum = 0, windowSum = 0;
    // soma inicial da primeira janela
    for (int i = 0; i <k; i++) {
        windowSum += nums[i]; // soma os k primeiros elementos
    }
    maxSum = windowSum; // armazena a soma maxima inicial
    // move a janela
    for (int i = k; i <n; i++) {
        windowSum += nums[i] - nums[i - k]; // adiciona o novo, remove o antigo da soma
        maxSum = max(maxSum, windowSum); // atualiza a soma maxima se necessario
    }
    return maxSum; // retorna a soma maxima da janela
}
