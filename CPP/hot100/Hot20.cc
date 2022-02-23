/*
 * Created by Xiaozhong on 2/21/2022.
 * Copyright (c) 2/21/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "unordered_map"
#include "stack"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapper;
        mapper[')'] = '(';
        mapper[']'] = '[';
        mapper['}'] = '{';
        stack<char> stk;
        for (const char &c: s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                if (stk.empty() || stk.top() != mapper[c]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};