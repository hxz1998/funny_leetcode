/**
 * Created by Xiaozhong on 2020/12/2.
 * Copyright (c) 2020/12/2 Xiaozhong. All rights reserved.
 */
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    vector<vector<vector<int>>> memo;
    int sz;

    int dp(vector<vector<int>> &grid, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;
        if (sz == r1 || sz == r2 || sz == c1 || sz == c2 ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -999999;
        } else if (r1 == sz - 1 && c1 == sz - 1) {
            return grid[r1][c1];
        } else if (memo[r1][c1][c2] != INT32_MAX) {
            return memo[r1][c1][c2];
        } else {
            int ans = grid[r1][c1];
            if (c1 != c2) ans += grid[r2][c2];
            ans += max(max(dp(grid, r1, c1 + 1, c2 + 1), dp(grid, r1 + 1, c1, c2 + 1)),
                       max(dp(grid, r1, c1 + 1, c2), dp(grid, r1 + 1, c1, c2)));
            memo[r1][c1][c2] = ans;
            return ans;
        }
    }

public:
    int cherryPickup(vector<vector<int>> &grid) {
        sz = grid.size();
        memo = vector<vector<vector<int>>>(sz, vector<vector<int>>(sz, vector<int>(sz, INT32_MAX)));
        return max(0, dp(grid, 0, 0, 0));
    }
};