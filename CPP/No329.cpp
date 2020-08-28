/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    // 方向转换矩阵
    static constexpr int dirs[4][2] = {{-1, 0},
                                       {0,  -1},
                                       {1,  0},
                                       {0,  1}};
    int rows, columns;  // 用来记录原始矩阵的尺寸

    int dfs(vector<vector<int>> &matrix, int row, int column, vector<vector<int>> &memo) {
        // 如果记忆矩阵中不为 0 ，那么说明计算过这个节点的最大长度了，直接返回
        if (memo[row][column]) return memo[row][column];

        ++memo[row][column];    // 将初始值设置为 1
        for (int i = 0; i < 4; i++) {
            int new_row = dirs[i][0] + row, new_column = dirs[i][1] + column;
            if (new_row >= 0 && new_row < rows && new_column >= 0 && new_column < columns &&
                matrix[new_row][new_column] > matrix[row][column])
                // 之所以这里还要再 + 1，是因为要增加一个路径节点了，加上自己（row， column）自己本身
                memo[row][column] = max(memo[row][column], dfs(matrix, new_row, new_column, memo) + 1);
        }
        return memo[row][column];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> memo(rows, vector<int>(columns, 0));
        int ans = 0;
        // 遍历整个矩阵，分别深度优先搜索查询
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }
};