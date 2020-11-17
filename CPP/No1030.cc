/**
 * Created by Xiaozhong on 2020/11/17.
 * Copyright (c) 2020/11/17 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ret;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                ret.push_back({i, j});
            }
        }
        sort(ret.begin(), ret.end(), [&](const vector<int> &rhs, const vector<int> &lhs) {
           return abs(rhs[0] - r0) + abs(rhs[1] - c0) < abs(lhs[0] - r0) + abs(lhs[1] - c0);
        });
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.allCellsDistOrder(2, 2, 0, 1);
    return 0;
}