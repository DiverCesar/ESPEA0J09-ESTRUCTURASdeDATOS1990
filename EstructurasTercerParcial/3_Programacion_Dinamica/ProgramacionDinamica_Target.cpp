#include <iostream>
#include <vector>

using namespace std;

int countWays(int target, vector<int>& nums) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int num : nums) {
            if (i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << "Numero de formas de obtener " << target << " es: " << countWays(target, nums) << endl;
    return 0;
}
