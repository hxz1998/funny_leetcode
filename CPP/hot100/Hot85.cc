/*
 * Created by Xiaozhong on 3/7/2022.
 * Copyright (c) 3/7/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2)));
        // 0 - 从上往下， 1 - 从左往右
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = matrix[i][j] == 1 ? 1 : 0;
                if (i == 0 && j == 0) {
                    dp[i][j][0] = val;
                    dp[i][j][1] = val;
                } else if (i == 0) {
                    dp[i][j][0] = val;
                    dp[i][j][1] = dp[i][j - 1][1] + val;
                } else if (j == 0) {
                    dp[i][j][0] = dp[i - 1][j][0] + val;
                    dp[i][j][1] = val;
                } else {
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) +
                }
            }
        }
    }
};