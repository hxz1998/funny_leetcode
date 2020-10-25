/**
 * Created by Xiaozhong on 2020/10/24.
 * Copyright (c) 2020/10/24 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int mod = 1000000007;
    vector<int> dp;
public:

    int waysToStep(int n) {
        dp.resize(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            if (i >= 2) dp[i] = (dp[i] + dp[i - 2]) % mod;
            if (i >= 3) dp[i] = (dp[i] + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    assert(s.waysToStep(5) == 13);
}