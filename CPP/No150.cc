/**
 * Created by Xiaozhong on 2020/8/14.
 * Copyright (c) 2020/8/14 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "string"
#include "stack"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int str_mid1, str_mid2;
        // 遇到运算符号后，根据符号来对数据进行运算并且入栈
        for (auto &v_mate : tokens) {
            if (v_mate == "+") {
                str_mid1 = s.top();
                s.pop();
                str_mid2 = s.top();
                s.pop();
                s.push(str_mid2 + str_mid1);
            } else if (v_mate == "-") {
                str_mid1 = s.top();
                s.pop();
                str_mid2 = s.top();
                s.pop();
                s.push(str_mid2 - str_mid1);
            } else if (v_mate == "*") {
                str_mid1 = s.top();
                s.pop();
                str_mid2 = s.top();
                s.pop();
                s.push(str_mid2 * str_mid1);
            } else if (v_mate == "/") {
                str_mid1 = s.top();
                s.pop();
                str_mid2 = s.top();
                s.pop();
                s.push(str_mid2 / str_mid1);
            } else s.push(stoi(v_mate));
        }
        return s.top();
    }
};