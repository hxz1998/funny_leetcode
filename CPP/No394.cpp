/**
 * Created by Xiaozhong on 2020/9/11.
 * Copyright (c) 2020/9/11 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    string getDigits(string &s, size_t &ptr) {
        string res = "";
        while (isdigit(s[ptr])) {
            res.push_back(s[ptr++]);
        }
        return res;
    }

    string getString(vector<string> &v) {
        string res;
        for (const auto &s : v) {
            res += s;
        }
        return res;
    }

public:
    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;
        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                stk.push_back(string(1, s[ptr++]));
            } else {
                ++ptr;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                stk.pop_back();
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                while (repTime--) t += o;
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};