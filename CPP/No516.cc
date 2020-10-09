/**
 * Created by Xiaozhong on 2020/10/9.
 * Copyright (c) 2020/10/9 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("cbbd") << endl;
}