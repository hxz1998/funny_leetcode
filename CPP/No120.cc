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
    // 滚动数组法，优化了空间复杂度
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size(), ans = 1e9;
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            // 为什么要倒着遍历？是因为在遍历过程中，需要用到前面的数值，如果正着来就不对了
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                if (j == triangle[i].size() - 1) dp[j + 1] = dp[j] + triangle[i][j];
                else if (j == 0) dp[j + 1] = dp[j + 1] + triangle[i][j];
                else dp[j + 1] = min(dp[j + 1], dp[j]) + triangle[i][j];
            }
        }
        // 在最后一列找到最小的值
        return *min_element(dp.begin() + 1, dp.end());
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

class Solution_OldVersion {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                // 边界条件，最右边那列，只能从上面直接下来
                if (j == triangle[i].size() - 1) dp[i + 1][j + 1] = triangle[i][j] + dp[i][j];
                    // 也是边界条件，最左边这列，只能从上面下来
                else if (j == 0) dp[i + 1][j + 1] = dp[i][j + 1] + triangle[i][j];
                    // 这才是一般情况，找一个上面下来的最小值
                else dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i][j]) + triangle[i][j];
            }
        }
        return *min_element(dp.back().begin() + 1, dp.back().end());
    }
};