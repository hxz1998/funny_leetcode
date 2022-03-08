/*
 * Created by Xiaozhong on 3/8/2022.
 * Copyright (c) 3/8/2022 Xiaozhong. All rights reserved.
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
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) return minDistance(word2, word1);
        int n = static_cast<int>(word1.size()), m = static_cast<int>(word2.size());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int idx = 0; idx <= m; ++idx) dp[0][idx] = idx;
        for (int idx = 0; idx <= n; ++idx) dp[idx][0] = idx;
        for (int i1 = 0; i1 < n; ++i1) {
            for (int i2 = 0; i2 < m; ++i2) {
                if (word1[i1] == word2[i2]) {
                    dp[i1][i2] = min(dp[i1 - 1][i2 - 1], min(dp[i1 - 1][i2] + 1, dp[i1][i2 - 1] + 1));
                } else {
                    dp[i1][i2] = 1 + min(dp[i1 - 1][i2 - 1], min(dp[i1 - 1][i2], dp[i1][i2 - 1]));
                }
            }
        }
        int ans = INT32_MAX;
        for (int idx = 0; idx < m; ++idx) ans = max(ans, dp[n][idx]);
        return ans;
    }
};