/**
 * Created by Xiaozhong on 2020/12/15.
 * Copyright (c) 2020/12/15 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int numTilings(int N) {
        static int mod = 1e9 + 7;
        int dp[N + 3];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= N; ++i) {
            // 动态转移方程
            dp[i] = (2 * dp[i - 1] % mod + dp[i - 3] % mod) % mod;
        }
        return dp[N];
    }
};

int main() {
    Solution s;
    cout << s.numTilings(4) << endl;
}