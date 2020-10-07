/**
 * Created by Xiaozhong on 2020/8/6.
 * Copyright (c) 2020/8/6 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
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