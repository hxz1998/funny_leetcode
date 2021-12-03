/*
 * Created by Xiaozhong on 12/2/2021.
 * Copyright (c) 12/2/2021 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    int dirs[4][2] = {{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}};
    int m = 0, n = 0;
public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (board[x][y] == word[0]) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[x][y] = true;
                    if (dfs(board, visited, x, y, word, 0)) return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(const vector<vector<char>> &board, vector<vector<bool>> &visited,
             int x, int y,
             const string &word, int start) {
        if (start == word.size() - 1) return true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && board[nx][ny] == word[start + 1]) {
                visited[nx][ny] = true;
                if (dfs(board, visited, nx, ny, word, start + 1)) return true;
                visited[nx][ny] = false;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'E', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    Solution s;
//    cout << s.exist(board, "ABCCED") << endl;
    cout << s.exist(board, "ABCESEEEFS") << endl;
//    board = {{'a', 'b'},
//             {'c', 'd'}};
//    cout << s.exist(board, "abcd") << endl;
}