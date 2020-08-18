/**
 * Created by Xiaozhong on 2020/8/18.
 * Copyright (c) 2020/8/18 Xiaozhong. All rights reserved.
 */
#include "vector"

using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>> &dungeon, vector<vector<int>> &visited, int i, int j, int m, int n) {
        // 到达终点，递归终止
        if (i == m - 1 && j == n - 1) return max(1 - dungeon[i][j], 1);
        // 如果之前已经计算过到达该点所用的健康点数，则直接返回
        if (visited[i][j] > 0) return visited[i][j];

        // 开始计算从 (i, j) 出发到终点所需要的最小值
        int ans = 0;
        // 如果碰到了最后一行，那么只能向右
        if (i == m - 1) ans = max(dfs(dungeon, visited, i, j + 1, m, n) - dungeon[i][j], 1);
        // 如果碰到了最后一列，那么只能向下
        else if (j == n - 1) ans = max(dfs(dungeon, visited, i + 1, j, m, n) - dungeon[i][j], 1);
        // 正常求值
        else
            ans = max(min(dfs(dungeon, visited, i + 1, j, m, n), dfs(dungeon, visited, i, j + 1, m, n)) - dungeon[i][j],
                      1);
        // 记录并返回
        return visited[i][j] = ans;
    }

public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        vector<vector<int>> visited(dungeon.size(), vector<int>(dungeon[0].size(), 0));
        return dfs(dungeon, visited, 0, 0, dungeon.size(), dungeon[0].size());
    }
};