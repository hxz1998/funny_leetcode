/**
 * Created by Xiaozhong on 2020/8/8.
 * Copyright (c) 2020/8/8 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#' ||
            board[i][j] == 'X')
            return;
        board[i][j] = '#';
        dfs(board, i - 1, j);   // 上
        dfs(board, i + 1, j);   // 下
        dfs(board, i, j - 1);   // 左
        dfs(board, i, j + 1);   // 右
    }

public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        // 首先对边缘元素进行标记
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 如果遇到边缘的 O， 那么就对其进行递归搜索，DFS哦~
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }
        // 最后将标记为 # 的替换回 O，将标记为 O 的替换为 X（说明不跟边界元素相连接）
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};