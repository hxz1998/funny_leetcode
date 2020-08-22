/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    bool cycle = false;
    int size = 0;
    void dfs(vector<vector<char>> &grid, int i, int j, char c, int start_x, int start_y, vector<vector<bool>> &visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if (grid[i][j] != c) return;
        visited[start_x][start_y] = false;
        if (visited[i][j]) return;
        visited[i][j] = true;
        size++;
        if (i == start_x && j == start_y && size >= 4) {
            cycle = true;
            return;
        }
        dfs(grid, i - 1, j, c, start_x, start_y, visited);
        dfs(grid, i + 1, j, c, start_x, start_y, visited);
        dfs(grid, i, j - 1, c, start_x, start_y, visited);
        dfs(grid, i, j + 1, c, start_x, start_y, visited);
        size--;
    }

public:
    bool containsCycle(vector<vector<char>> &grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (cycle) return cycle;
                dfs(grid, 0, 0, grid[i][j], i, j, visited);
            }
        }
        return cycle;
    }
};

int main() {
    vector<vector<char>> grid = {
            {'a', 'b', 'b'},
            {'b', 'z', 'b'},
            {'b', 'b', 'a'}
    };
    Solution s;
    cout << s.containsCycle(grid) << endl;
}