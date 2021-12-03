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
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        dfs(visited, 0, 0, m, n, k);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) ++ans;
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<bool>> &visited, int x, int y, int m, int n, int k) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && evaluate(nx, ny) <= k && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(visited, nx, ny, m, n, k);
            }
        }
    }

    int evaluate(int x, int y) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        while (y > 0) {
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.movingCount(2, 3, 1) << endl;
    cout << s.movingCount(3, 1, 0) << endl;
}