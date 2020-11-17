/**
 * Created by Xiaozhong on 2020/11/14.
 * Copyright (c) 2020/11/14 Xiaozhong. All rights reserved.
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'a') {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1] + 1;
            } else {
                dp[0][i] = dp[0][i - 1] + 1;
                dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]);
            }
        }
        return min(dp[1][n], dp[0][n]);
    }
};

int main() {
    Solution s;
    cout << s.minimumDeletions("aababbab") << endl;
}