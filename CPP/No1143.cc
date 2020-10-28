/**
 * Created by Xiaozhong on 2020/10/27.
 * Copyright (c) 2020/10/27 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

/**
 * 动态规划，是一种双串匹配 DP 模型，在这里初始化二维的动态记忆矩阵 dp(n + 1, m + 1)
 * 然后使用状态方程进行更新，dp[i][j] 表示到串 1 的第 i 个字符和串 2 的第 j 个字符最长的子串长度
 * 1. 如果 [i - 1] == [j - 1] 那么 dp[i][j] = dp[i - 1][j - 1] + 1
 * 2. 否则 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution s;
    assert(s.longestCommonSubsequence("abcde", "ace") == 3);
}