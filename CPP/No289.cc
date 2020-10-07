/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include "vector"

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 左上-上-右上-左-右-左下-下-右下
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int sum = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k], ny = j + dy[k]; // 转换坐标
                    if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())    // 判断下标是否合法
                        sum += (board[nx][ny] & 1);
                }
                // 更新状态到更高位上
                if (board[i][j] == 1) {                 // 原先是存活状态
                    if (sum == 2 || sum == 3)
                        board[i][j] |= 2;               // 使用 2 来标记新的生存状态，之所以使用 |= ，是因为要保留原来的生存状态
                } else {                                // 原先是死亡状态，那么现在将新的状态更新到第二位（存活辣）
                    if (sum == 3) board[i][j] |= 2;
                }
            }
        }
        // 然后将倒数第 2 位上的结果移过来
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] >>= 1;
            }
        }
    }
};