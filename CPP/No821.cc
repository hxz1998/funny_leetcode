/**
 * Created by Xiaozhong on 2020/12/12.
 * Copyright (c) 2020/12/12 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.length();
        vector<int> ans(n);
        int prev = INT32_MIN / 2;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) prev = i;
            ans[i] = i - prev;
        }
        prev = INT32_MAX / 2;
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) prev = i;
            ans[i] = min(prev - i, ans[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ans;
    ans = s.shortestToChar("loveleetcode", 'e');
    return 0;
}