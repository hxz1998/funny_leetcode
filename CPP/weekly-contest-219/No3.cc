/**
 * Created by Xiaozhong on 2020/12/13.
 * Copyright (c) 2020/12/13 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int> &stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i == j) dp[i][j] = stones[i];
                else dp[i][j] = dp[i][j - 1] + stones[j];
            }
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (j - i == 1) res[i][j] = max(stones[i], stones[j]);
                else res[i][j] = max(dp[i + 1][j] - res[i + 1][j], dp[i][j - 1] - res[i][j - 1]);
            }
        }
        return res[0][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> stones = {5, 3, 1, 4, 2};
    cout << s.stoneGameVII(stones);
}