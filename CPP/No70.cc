/**
 * Created by Xiaozhong on 2020/7/23.
 * Copyright (c) 2020/7/23 Xiaozhong. All rights reserved.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(3) << endl;
}