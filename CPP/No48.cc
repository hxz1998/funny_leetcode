/**
 * Created by Xiaozhong on 2020/7/17.
 * Copyright (c) 2020/7/17 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * 对于矩阵原地旋转问题，可以对其先进行转置，然后再进行左右交换，这是一个小技巧！
 */
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        // 先进行转置操作
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        // 再完成交换操作
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
};

int main(int argc, char *args[]) {
    Solution s;
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    s.rotate(matrix);
    for (vector<int> row : matrix) {
        for (int column : row) {
            cout << column << " ";
        }
        cout << endl;
    }
}