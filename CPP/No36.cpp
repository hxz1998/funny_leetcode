/**
 * Created by Xiaozhong on 2020/7/13.
 * Copyright (c) 2020/7/13 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        /**
         * 用来存储行、列、盒子的数组
         */
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> column(9, vector<int>(9, 0));
        vector<vector<int>> box(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                // 计算子数独位置
                int box_index = (i / 3) * 3 + j / 3;
                // 转换成整型
                int val = board[i][j] - '1';
                // 检查行上是不是满足，列上是不是满足，以及子数独中是否满足
                if (row[i][val] == 0 && column[j][val] == 0 && box[box_index][val] == 0) {
                    row[i][val] = 1;
                    column[j][val] = 1;
                    box[box_index][val] = 1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << s.isValidSudoku(board) << endl;
}