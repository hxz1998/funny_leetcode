/*
 * Created by Xiaozhong on 2/21/2022.
 * Copyright (c) 2/21/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
private:
    void backtrack(vector<string> &ans, int open, int close, string &buffer, int n) {
        if (buffer.size() == 2 * n) {
            ans.emplace_back(buffer);
            return;
        }
        if (open < n) {
            buffer.push_back('(');
            backtrack(ans, open + 1, close, buffer, n);
            buffer.pop_back();
        }
        if (close < open) {
            buffer.push_back(')');
            backtrack(ans, open, close + 1, buffer, n);
            buffer.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string buffer;
        backtrack(ans, 0, 0, buffer, n);
        return ans;
    }
};