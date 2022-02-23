/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "vector"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x == 0 || y == 0) dp[x][y] = 1;
                else dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    cout << s.uniquePaths(1, 1) << endl;
}