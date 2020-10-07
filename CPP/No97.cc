/**
 * Created by Xiaozhong on 2020/7/31.
 * Copyright (c) 2020/7/31 Xiaozhong. All rights reserved.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), mn = s3.size();
        if (n + m != mn) return false;
        vector<vector<int>> f = vector<vector<int>>(n + 1, vector<int>(m + 1, false));
        f[0][0] = true;
        // 典型的动态规划题目，使用状态转移方程来完成
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                if (j > 0) f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
            }
        }
        return f[n][m];
    }
};

int main(int argc, char **args) {
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
}