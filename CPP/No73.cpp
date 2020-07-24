/**
 * Created by Xiaozhong on 2020/7/24.
 * Copyright (c) 2020/7/24 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        set<int> row;
        set<int> col;
        // 首先遍历第一遍，用set记录下来元素值为 0 的行标和列标
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        // 第二遍遍历的时候，需要把行标或者列标为 0 的地方置为0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row.count(i) || col.count(j))
                    matrix[i][j] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
    };
    Solution s;
    s.setZeroes(matrix);
    for (vector<int> item : matrix) {
        for (int i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}