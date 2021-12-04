/*
 * Created by Xiaozhong on 12/2/2021.
 * Copyright (c) 12/2/2021 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numWays(int n) {
        if (n == 0) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int idx = 2; idx <= n; ++idx) {
            dp[idx] = (dp[idx - 1] % mod + dp[idx - 2] % mod) % mod;
        }
        return dp[n] % mod;
    }
};

int main() {
    Solution s;
    cout << s.numWays(7) << endl;
    cout << s.numWays(1) << endl;
    cout << s.numWays(0) << endl;
    cout << (s.numWays(44) == 134903163) << endl;
}