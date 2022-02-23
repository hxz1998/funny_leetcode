/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int idx = 2; idx <= n; ++idx) {
            dp[idx] = dp[idx - 1] + dp[idx - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(3) << endl << s.climbStairs(2) << endl;
}