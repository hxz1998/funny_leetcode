/*
 * Created by Xiaozhong on 2/28/2022.
 * Copyright (c) 2/28/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxEdgeLength = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (row == 0 || col == 0) dp[row][col] = matrix[row][col] == '1' ? 1 : 0;
                else {
                    if (matrix[row][col] == '0') dp[row][col] = 0;
                    else dp[row][col] = min(min(dp[row - 1][col], dp[row][col - 1]), dp[row - 1][col - 1]) + 1;
                }
                maxEdgeLength = max(maxEdgeLength, dp[row][col]);
            }
        }
        return maxEdgeLength * maxEdgeLength;
    }
};