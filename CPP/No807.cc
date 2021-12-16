/**
 * Created by Xiaozhong on 2020/12/23.
 * Copyright (c) 2020/12/23 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

/*
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> rowMaxs(n), columnMaxs(n);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                rowMaxs[r] = max(rowMaxs[r], grid[r][c]);
                columnMaxs[c] = max(columnMaxs[c], grid[r][c]);
            }
        }
        int ans = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                ans += min(rowMaxs[r], columnMaxs[c]) - grid[r][c];
            }
        }
        return ans;
    }
};*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        vector<int> rowMaxValue(n), columnMaxValue(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMaxValue[i] = max(rowMaxValue[i], grid[i][j]);
                columnMaxValue[j] = max(columnMaxValue[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += max(min(columnMaxValue[j], rowMaxValue[i]) - grid[i][j], 0);
            }
        }
        return ans;
    }
};
