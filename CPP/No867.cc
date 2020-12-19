/**
 * Created by Xiaozhong on 2020/12/19.
 * Copyright (c) 2020/12/19 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        int n = A.size(), m = A.front().size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ret[j][i] = A[i][j];
            }
        }
        return ret;
    }
};