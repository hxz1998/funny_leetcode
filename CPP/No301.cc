/*
 * Created by Xiaozhong on 10/27/2021.
 * Copyright (c) 10/27/2021 Xiaozhong. All rights reserved.
 */
#include "libs.hh"

class Solution {
    unordered_set<string> uSet;

public:

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0, rightRemove = 0;
        for (int idx = 0; idx < s.length(); ++idx) {
            if (s[idx] == '(') leftRemove++;
            else if (s[idx] == ')') {
                if (leftRemove > 0) leftRemove--;
                else rightRemove++;
            }
        }
        string path;
        backtrack(0, 0, 0, leftRemove, rightRemove, path, s);
        return vector<string>(uSet.begin(), uSet.end());
    }

private:
    void backtrack(int idx, int leftCount, int rightCount, int leftRemove, int rightRemove, string path, string &s) {
        if (idx == s.length()) {
            if (leftRemove == 0 && rightRemove == 0) uSet.insert(path);
            return;
        }
        char c = s[idx];
        if (c == '(' && leftRemove > 0) backtrack(idx + 1, leftCount, rightCount, leftRemove - 1, rightRemove, path, s);
        if (c == ')' && rightRemove > 0)
            backtrack(idx + 1, leftCount, rightCount, leftRemove, rightRemove - 1, path, s);
        path.push_back(c);
        if (c != '(' && c != ')') backtrack(idx + 1, leftCount, rightCount, leftRemove, rightRemove, path, s);
        else if (c == '(') backtrack(idx + 1, leftCount + 1, rightCount, leftRemove, rightRemove, path, s);
        else if (rightCount < leftCount)
            backtrack(idx + 1, leftCount, rightCount + 1, leftRemove, rightRemove, path, s);
        path.pop_back();
    }

};

int main() {
    Solution solution;
    solution.removeInvalidParentheses(")(");
};