/*
 * Created by Xiaozhong on 11/3/2021.
 * Copyright (c) 11/3/2021 Xiaozhong. All rights reserved.
 */
#include <queue>
#include "libs.hh"

using namespace std;

struct cmp {
    bool operator()(const int lhs[], const int rhs[]) {
        return lhs[2] > rhs[2];
    }
};
class Solution {
private:

public:
    int trapRainWater(vector<vector<int>> &heights) {
        priority_queue<int[], vector<int[]>, cmp> pq(cmp);
        if (heights.empty() || heights[0].empty()) return 0;
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {

                }
            }
        }
    }
};