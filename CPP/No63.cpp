/**
 * Created by Xiaozhong on 2020/7/22.
 * Copyright (c) 2020/7/22 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // 记录行 m 和列 n
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        // 对左上角到达的方式进行初始化指定
        dp[0][0] = !obstacleGrid[0][0];
        // 第一列的元素，都只能为 1（当前不为零且上面的可达）或者 0
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        // 对于第一行的元素也一样
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) dp[0][i] = 1;
        // 开始使用状态方程进行更新操作
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i - 1][j] + dp[i][j - 1] : 0;
            }
        }
        // 返回右下角结果
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> matrix = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    Solution s;
    cout << s.uniquePathsWithObstacles(matrix) << endl;
}