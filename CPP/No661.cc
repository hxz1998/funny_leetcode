/**
 * Created by Xiaozhong on 2020/11/8.
 * Copyright (c) 2020/11/8 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int n = M.size(), m = M.front().size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                int count = 0;
                for (int nr = r - 1; nr <= r + 1; ++nr) {
                    for (int nc = c - 1; nc <= c + 1; ++nc) {
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                            ++count;
                            ans[r][c] += M[nr][nc];
                        }
                    }
                }
                ans[r][c] /= count;
            }
        }
        return ans;
    }
};