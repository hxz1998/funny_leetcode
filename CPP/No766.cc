/**
 * Created by Xiaozhong on 2020/12/5.
 * Copyright (c) 2020/12/5 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.front().size(); ++j) {
                if (i > 0 && j > 0 && matrix[i][j] != matrix[i - 1][j - 1]) return false;
            }
        }
        return true;
    }
};