#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, const vector<int>& nums) {
    int left = 0, sum = 0, minLength = INT_MAX;
    for (int right = 0; right <nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return (minLength == INT_MAX) ? 0 : minLength;
}
