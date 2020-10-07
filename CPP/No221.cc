/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int max_side = 0;
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(column));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i][j] = 1; // 遇到了边界，此时需要赋值为 1
                    else dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1; // 状态转移方程
                    max_side = max(max_side, dp[i][j]); // 求边的最大值
                }
            }
        }
        return max_side * max_side; // 求最大面积
    }
};

int main() {
    vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0',},
            {'1', '0', '1', '1', '1',},
            {'1', '1', '1', '1', '1',},
            {'1', '0', '0', '1', '0'}
    };
    Solution s;
    cout << s.maximalSquare(matrix) << endl;
}
