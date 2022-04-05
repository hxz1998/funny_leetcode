/**
 * Created by Xiaozhong on 2022/3/18.
 * Copyright (c) 2022/3/18 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{1,  0},
                                {-1, 0},
                                {0,  1},
                                {0,  -1}};

    int helper(const vector<vector<int>> &matrix,
               vector<vector<int>> &dp,
               int x, int y) {
        if (dp[x][y] != 0) return dp[x][y];
        dp[x][y]++;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() &&
                matrix[nx][ny] > matrix[x][y]) {
                dp[x][y] = max(dp[x][y],
                               helper(matrix, dp, nx, ny) + 1);
            }
        }
        return dp[x][y];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = static_cast<int>(matrix.size()), m = static_cast<int>(matrix[0].size());
        vector<vector<int>> dp(n, vector<int>(m));
        int ans = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                ans = max(helper(matrix, dp, x, y), ans);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{3, 4, 5},
                                  {3, 2, 6},
                                  {2, 2, 1}};
    cout << s.longestIncreasingPath(matrix) << endl;
}