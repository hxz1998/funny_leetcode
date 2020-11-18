/**
 * Created by Xiaozhong on 2020/11/18.
 * Copyright (c) 2020/11/18 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    int ans = 0, n, m;

    void dfs(vector<vector<int>> &grid, int r, int c, int &tmp) {
        // 如果已经被访问过了，那么就直接返回，不再检查
        if (grid[r][c] == -1) return;
        // 没有被访问过，而且是一个岛屿
        if (grid[r][c] == 1) {
            grid[r][c] = -1;// 首先标记来过了
            ++tmp;          // 再叠加面积
            // 对上下左右四个方向进行深度优先搜索
            for (int i = 0; i < 4; ++i) {
                int cr = r + dr[i], cc = c + dc[i];
                // 判断边界条件
                if (cr >= 0 && cr < n && cc >= 0 && cc < m) {
                    dfs(grid, cr, cc, tmp);
                }
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        n = grid.size(), m = grid.front().size();
        // 逐行逐列去遍历，看看哪一个单元格还没被访问到
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // 如果单元格被访问过了，或者这个单元格本来就是一滩水，那么就跳过，省的函数调用
                if (grid[i][j] == -1 || grid[i][j] == 0) continue;
                int tmp = 0; // 记录每次出发能够获得的岛屿面积
                dfs(grid, i, j, tmp);
                ans = max(tmp, ans);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}
    };
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;
}