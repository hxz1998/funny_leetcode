/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> uSet;
        for (const string &str: wordDict) uSet.insert(str);

        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && uSet.find(s.substr(j, i - j)) != uSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    Solution s;
    vector<string> wordDict = {"leet", "code"};
    cout << boolalpha << s.wordBreak("leetcode", wordDict) << endl;
}