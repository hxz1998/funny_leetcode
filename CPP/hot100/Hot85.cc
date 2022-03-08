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
        int n = static_cast<int>( matrix.size()), m = static_cast<int>((int) matrix[0].size());
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') continue;
                if (i == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') continue;
                if (ans >= dp[i][j] * m) continue;
                int left = j, right = j;
                while (left >= 0 && dp[i][left] >= dp[i][j]) left--;
                while (right < m && dp[i][right] >= dp[i][j]) right++;
                ans = max(ans, (right - left - 1) * dp[i][j]);
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