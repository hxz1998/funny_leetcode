/**
 * Created by Xiaozhong on 2020/12/9.
 * Copyright (c) 2020/12/9 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


class Solution {
    vector<vector<int>> grid;
public:
    int swimInWater(vector<vector<int>> &_grid) {
        grid = _grid;
        vector<vector<int>> addr = {{-1, 0},
                                    {0,  1},
                                    {1,  0},
                                    {0,  -1}};
        int m = grid.size(), n = grid.front().size();
        priority_queue<vector<int>, vector<vector<int>>, Solution> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.push({0, 0});
        visited[0][0] = true;
        int ans = 0;
        while (!pq.empty()) {
            vector<int> val = pq.top();
            pq.pop();
            if (val.front() == m - 1 && val.back() == n - 1) return ans;
            for (vector<int> item : addr) {
                int x = val.front() + item.front(), y = val.back() + item.back();
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                pq.push({x, y});
                visited[x][y] = true;
            }
        }
        return -1;
    }

    bool operator()(const vector<int> &lhs, const vector<int> &rhs) {
        return grid[rhs[0]][lhs[1]] < grid[lhs[0]][rhs[1]];
    }
};

int main() {
    vector<vector<int>> grid = {
            {0, 2},
            {1, 3}
    };
    Solution s;
    cout << s.swimInWater(grid) << endl;
}