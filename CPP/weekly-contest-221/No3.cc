/**
 * Created by Xiaozhong on 2020/12/27.
 * Copyright (c) 2020/12/27 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int m, n;

    int find(const vector<vector<int>> &grid, int j) {
        for (int i = 0; i < m;) {
            if (j + 1 < n && grid[i][j] == 1 && grid[i][j + 1] == 1) {
                ++i, ++j;
            } else if (j - 1 >= 0 && grid[i][j] == -1 && grid[i][j - 1] == -1) {
                ++i, --j;
            } else return -1;
        }
        return j;
    }

public:
    vector<int> findBall(vector<vector<int>> &grid) {
        m = grid.size(), n = grid.front().size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(find(grid, i));
        }
        return ans;
    }
};