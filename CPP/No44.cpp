/**
 * Created by Xiaozhong on 2020/7/17.
 * Copyright (c) 2020/7/17 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 边界条件
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            // 如果匹配模式为 * ， 那么就会把后面的也视作 true
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        // 对整个扫描矩阵进行更新处理，依据是状态转移方程
        /*
         *              d[i - 1][j - 1]                 s_i 与 p_j 相同或者 p_j 是问号
         *            /
         * dp[i][j] = - dp[i][j - 1] || dp[i - 1][j]    p_j 是星号
         *            \
         *              False                           其他情况
         */
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        // 返回结果
        return dp[m][n];
    }
};

int main(int argc, char *args[]) {
    Solution s;
    cout << s.isMatch("cb", "?a") << endl;
    cout << s.isMatch("adceb", "*a*b") << endl;
    cout << s.isMatch("acdcb", "a*c?b") << endl;

}