/**
 * Created by Xiaozhong on 2022/4/3.
 * Copyright (c) 2022/4/3 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> grid) {
        int n = static_cast<int>(grid.size()), m = static_cast<int>(grid.front().size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] = grid[i][j] + grid[i][j - 1];
                else if (j == 0) grid[i][j] = grid[i][j] + grid[i - 1][j];
                else {
                    grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[n - 1][m - 1];
    }
};