/**
 * Created by Xiaozhong on 2020/9/17.
 * Copyright (c) 2020/9/17 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>> &board) {
        int sum = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    ++sum;
                    if (j - 1 >= 0 && board[i][j - 1] == 'X') --sum;
                    if (i - 1 >= 0 && board[i - 1][j] == 'X') --sum;
                }
            }
        }
        return sum;
    }
};