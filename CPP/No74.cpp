/**
 * Created by Xiaozhong on 2020/7/24.
 * Copyright (c) 2020/7/24 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size(), i = 1;
        // 检查可能出现在哪一行，主要检查对象为当前行的第一个元素，如果该元素大于了目标值，那么就可以视为目标可能在本行的前一行
        // 也可以对最后一列直接来一个二分查找，这样两个二分查找
        for (; i < m; ++i) {
            if (matrix[i][0] > target) break;
        }
        // 二分法查找
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[i - 1][mid] == target) {
                return true;
            } else if (matrix[i - 1][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
            {1,  3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
//    vector<vector<int>> matrix = {
//            {1}
//    };
    Solution s;
    cout << s.searchMatrix(matrix, 13);
}