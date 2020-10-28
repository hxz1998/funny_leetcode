/**
 * Created by Xiaozhong on 2020/8/6.
 * Copyright (c) 2020/8/6 Xiaozhong. All rights reserved.
 */

#include <algorithm>
#include "iostream"
#include "vector"
#include <cassert>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == triangle[i].size() - 1) dp[i + 1][j + 1] = triangle[i][j] + dp[i][j];
                else if (j == 0) dp[i + 1][j + 1] = dp[i][j + 1] + triangle[i][j];
                else dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i][j]) + triangle[i][j];
            }
        }
        return *min_element(dp.back().begin() + 1, dp.back().end());
    }
};

int main() {
    Solution s;
    vector<vector<int>> triangle = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    assert(s.minimumTotal(triangle) == 11);
}

class Solution_DFS {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> memo(triangle.size(), vector<int>(triangle.size()));
        return dfs(triangle, 0, 0, memo);
    }

private:
    int dfs(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &memo) {
        if (i == triangle.size()) return 0;
        if (!memo[i][j])
            memo[i][j] = min(dfs(triangle, i + 1, j, memo), dfs(triangle, i + 1, j + 1, memo)) + triangle[i][j];
        return memo[i][j];
    }
};