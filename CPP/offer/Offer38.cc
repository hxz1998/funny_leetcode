/*
 * Created by Xiaozhong on 12/13/2021.
 * Copyright (c) 12/13/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<string> ans;
public:
    vector<string> permutation(string s) {
        vector<bool> used(s.length());
        sort(s.begin(), s.end());
        string buffer;
        backtrace(s, used, buffer);
        return ans;
    }

private:
    void backtrace(const string &s, vector<bool> &used, string &buffer) {
        if (buffer.length() == s.length()) {
            ans.emplace_back(buffer);
            return;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (used[i] || (i > 0 && used[i - 1] && s[i] == s[i - 1])) continue;
            used[i] = true;
            buffer.push_back(s[i]);
            backtrace(s, used, buffer);
            buffer.pop_back();
            used[i] = false;
        }
    }
};