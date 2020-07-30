/**
 * Created by Xiaozhong on 2020/7/28.
 * Copyright (c) 2020/7/28 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty()) return false;        // 临界值判断
        this->m = board.size();                 // 记录行数
        this->n = board[0].size();              // 记录列数
        this->word = word;
        this->board = board;
        vector<vector<bool>> visited(m, vector<bool>(n));
        // 从左到右从上到下挨个作为起点来进行扫描
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, visited))  //扫描到符合要求的，则直接返回true
                    return true;
            }
        }
        return false;
    }

private:
    int m, n;
    string word;
    vector<vector<char>> board;
    // 上下左右坐标变换矩阵
    /*
     *            x,y - 1
     *   x - 1,y    x,y     x + 1, y
     *            x,y + 1
     */
    int direction[4][2] = {{-1, 0},
                           {0,  -1},
                           {0,  1},
                           {1,  0}};

    bool in_area(int x, int y) {
        // 判断 (x,y) 是否在合理区域内
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 回溯算法
    bool dfs(int x, int y, int start, vector<vector<bool>> &visited) {
        // 判断是不是匹配到了最后一个字符
        if (start == word.length() - 1) return board[x][y] == word[start];

        // 如果当前的字符匹配到了，那么就继续看四周有没有合适的
        if (board[x][y] == word[start]) {
            // 标记访问过的节点
            visited[x][y] = true;
            for (int k = 0; k < 4; k++) {
                // 获取到新的 X，Y
                int newX = x + direction[k][0];
                int newY = y + direction[k][1];
                // 看看是不是访问过，以及节点的合理
                if (in_area(newX, newY) && !visited[newX][newY]) {
                    if (dfs(newX, newY, start + 1, visited)) {
                        return true;
                    }
                }
            }
            // 回溯，取消标记
            visited[x][y] = false;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    cout << s.exist(board, "ABCCED") << endl;
}
