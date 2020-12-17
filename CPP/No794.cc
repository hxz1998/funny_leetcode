/**
 * Created by Xiaozhong on 2020/12/17.
 * Copyright (c) 2020/12/17 Xiaozhong. All rights reserved.
 */
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string> &board) {
        int xCount = 0, oCount = 0;
        for (string row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                else if (c == 'O') oCount++;
            }
        }
        // 对出现的数据进行检查，首先检查数据是否符合要求，然后再看某一方赢的情况下是否符合要求
        if (oCount != xCount && oCount != xCount - 1) return false;
        if (win(board, 'X') && oCount != xCount - 1) return false;
        if (win(board, 'O') && oCount != xCount) return false;
        return true;
    }

private:
    bool win(const vector<string> &board, char p) {
        for (int i = 0; i < 3; ++i) {
            // 检查行与列是否满足要求
            if (p == board[0][i] && p == board[1][i] && p == board[2][i]) return true;
            if (p == board[i][0] && p == board[i][1] && p == board[i][2]) return true;
        }
        if (p == board[0][0] && p == board[1][1] && p == board[2][2]) return true;
        if (p == board[0][2] && p == board[1][1] && p == board[2][0]) return true;
        return false;
    }
};