/*
 * Created by Xiaozhong on 3/2/2022.
 * Copyright (c) 3/2/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == matrix[0].size()) return matrix[0][0] == target;
        int row = matrix.size() - 1, column = 0;
        while (true) {
            if (row < 0 || column > matrix[0].size()) return false;
            if (matrix[row][column] < target) column++;
            else if (matrix[row][column] > target) row--;
            else return true;
        }
    }
};

