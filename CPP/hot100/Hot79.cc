/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0},
                                {1,  0},
                                {0,  1},
                                {0,  -1}};
    bool ans = false;
public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size();
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if (board[x][y] == word[0]) {
                    visited[x][y] = true;
                    dfs(board, word, 1, visited, x, y);
                }
                if (ans) return ans;
            }
        }
        return ans;
    }

private:
    void dfs(const vector<vector<char>> &board, const string &word, int start,
             vector<vector<bool>> &visited,
             int x, int y) {
        if (start == word.size()) {
            ans = true;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visited[nx][ny] &&
                board[nx][ny] == word[start]) {
                visited[nx][ny] = true;
                dfs(board, word, start + 1, visited, nx, ny);
                visited[nx][ny] = false;
            }
        }
    }
};