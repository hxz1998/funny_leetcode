/**
 * Created by Xiaozhong on 2020/7/22.
 * Copyright (c) 2020/7/22 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        // dp[i][j] 用来记录到达 i-j 位置的最短路径
        // 之所以注释掉，是因为可以很好的使用原有内存，不必开辟新的空间
//        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 为左上角起点时，直接获取值
//                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                if (i == 0 && j == 0) grid[i][j] = grid[i][j];
                    // 为第一行数据时，只能从左侧获取最小值
//                else if (i == 0) dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if (i == 0) grid[i][j] = grid[i][j] + grid[i][j - 1];
                    // 为第一列数据时，只能从上面获取最小值
//                else if (j == 0) dp[i][j] = grid[i][j] + dp[i - 1][j];
                else if (j == 0) grid[i][j] = grid[i][j] + grid[i - 1][j];
                    // 否则，就要考虑上方和左侧来的最小值
//                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                else grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        // 返回右下角数据，即为最终答案
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    cout << s.minPathSum(grid);
}