/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = matrix.size() - 1, column = 0;
        while (row >= 0 && column < matrix[0].size()) {
            if (matrix[row][column] > target) row--;
            else if (matrix[row][column] < target) column++;
            else return true;
        }
        return false;
    }
};