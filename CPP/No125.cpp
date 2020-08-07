/**
 * Created by Xiaozhong on 2020/8/7.
 * Copyright (c) 2020/8/7 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string buf;
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                buf += tolower(s[i]);
            }
        }
        string buf_rev(buf.rbegin(), buf.rend());
        return buf == buf_rev;
    }
};