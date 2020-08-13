/**
 * Created by Xiaozhong on 2020/8/13.
 * Copyright (c) 2020/8/13 Xiaozhong. All rights reserved.
 */

#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (!dp[i]) continue;
            for (auto &word : wordDict)
                if (word.size() + i <= s.size() && s.substr(i, word.size()) == word)
                    dp[i + word.size()] = true;

        }
        return dp[s.size()];
    }
};