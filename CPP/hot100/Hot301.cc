/*
 * Created by Xiaozhong on 3/10/2022.
 * Copyright (c) 3/10/2022 Xiaozhong. All rights reserved.
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
private:
    int len = 0;

    void helper(const string &str, string &buffer,
                unordered_set<string> &ans,
                int score, int start, int mx) {
        if (score < 0 || score > mx) return;
        if (start == str.size()) {
            if (score == 0 && buffer.size() >= len) {
                if (buffer.size() > len) ans.clear();
                len = static_cast<int>(buffer.size());
                ans.insert(buffer);
            }
            return;
        }

        char c = str[start];
        if (c == '(') {
            helper(str, buffer, ans, score, start + 1, mx);
            buffer.push_back(c);
            helper(str, buffer, ans, score + 1, start + 1, mx);
            buffer.pop_back();
        } else if (c == ')') {
            helper(str, buffer, ans, score, start + 1, mx);
            buffer.push_back(c);
            helper(str, buffer, ans, score - 1, start + 1, mx);
            buffer.pop_back();
        } else {
            buffer.push_back(c);
            helper(str, buffer, ans, score, start + 1, mx);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int n = static_cast<int>(s.size());
        string buffer;
        int left = 0, right = 0;
        for (const char &c: s) {
            if (c == '(') left++;
            else if (c == ')') right++;
        }
        int mx = min(left, right);
        unordered_set<string> uSet;
        helper(s, buffer, uSet, 0, 0, mx);
        return vector<string>(uSet.begin(), uSet.end());
    }
};

int main() {
    Solution s;
    s.removeInvalidParentheses("()())()");
}