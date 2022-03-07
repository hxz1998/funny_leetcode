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
    int longestValidParentheses(string s) {
        int n = (int) s.size();
        vector<int> dp(n);
        for (int idx = 0; idx < n; ++idx) {
            if (s[idx] == ')') {
                if (idx >= 2 && s[idx - 1] == '(') dp[idx] = dp[idx - 2] + 2;
                else if (idx - dp[idx - 1] - 1 >= 0 && s[idx - dp[idx - 1] - 1] == '(')
                    dp[idx] = dp[idx - 1] + (idx - dp[idx - 1] - 2 >= 0 ? dp[idx - dp[idx - 1] - 2] : 0) + 2;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses(")()())") << endl;
    cout << s.longestValidParentheses("()(()") << endl;
}