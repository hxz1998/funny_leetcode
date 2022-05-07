/**
 * Created by Xiaozhong on 2022/4/29.
 * Copyright (c) 2022/4/29 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x == 0 && y == 0) dp[x][y] = 1;
                else if (x == 0) dp[x][y] = 1;
                else if (y == 0) dp[x][y] = 1;
                else {
                    dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};