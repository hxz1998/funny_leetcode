/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int tmp = 0;
        for (int x = 0; x < n / 2; ++x) {
            for (int y = 0; y < (n + 1) / 2; ++y) {
                tmp = matrix[x][y];
                matrix[x][y] = matrix[n - 1 - y][x];
                matrix[n - 1 - y][x] = matrix[n - x - 1][n - y - 1];
                matrix[n - y - 1][n - x - 1] = matrix[y][n - x - 1];
                matrix[y][n - x - 1] = tmp;
            }
        }
    }
};