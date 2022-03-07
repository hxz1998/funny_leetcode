/*
 * Created by Xiaozhong on 3/7/2022.
 * Copyright (c) 3/7/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3)));
        int ans = 0;
        // 0 - 从上往下, 1 - 从左往右, 2 - 斜对角线
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = matrix[i][j] == '1' ? 1 : 0;
                if (val == 0) continue;
                if (i == 0 && j == 0) {
                    dp[i][j][0] = val;
                    dp[i][j][1] = val;
                    dp[i][j][2] = val;
                    ans = 1;
                } else if (i == 0) {
                    dp[i][j][0] = val;
                    dp[i][j][1] = dp[i][j - 1][1] + val;
                    dp[i][j][2] = val;
                    ans = max(ans, 1 * dp[i][j][1]);
                } else if (j == 0) {
                    dp[i][j][0] = dp[i - 1][j][0] + val;
                    dp[i][j][1] = val;
                    dp[i][j][2] = val;
                    ans = max(ans, 1 * dp[i][j][0]);
                } else {
                    int a = dp[i][j][0] = dp[i - 1][j][0] + val;
                    int b = dp[i][j][1] = dp[i][j - 1][1] + val;
                    int c = dp[i][j][2] = dp[i - 1][j - 1][2] + val;
                    if (a == 1 || b == 1 || c == 1) {
                        ans = max(ans, 1 * max(a, max(b, c)));
                    } else {
                        ans = max(ans, min(a, c) * min(b, c));
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    Solution s;
    cout << s.maximalRectangle(matrix) << endl;
}