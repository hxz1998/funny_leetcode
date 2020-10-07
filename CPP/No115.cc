/**
 * Created by Xiaozhong on 2020/8/5.
 * Copyright (c) 2020/8/5 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        long dp[t.size() + 1][s.size() + 1];
        for (int i = 0; i < s.size() + 1; i++) dp[0][i] = 1;
        for (int i = 1; i < t.size() + 1; i++) {
            for (int j = 1; j < s.size() + 1; j++) {
                if (s[j - 1] == t[i - 1])  dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[t.length()][s.length()];
    }
};