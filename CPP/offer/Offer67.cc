/**
 * Created by Xiaozhong on 2021/12/28.
 * Copyright (c) 2021/12/28 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int begin = 0, sign = 1, boundary = INT32_MAX / 10, ans = 0;
        while (begin < str.length() && str[begin] == ' ') {
            if (++begin == str.length()) return 0;
        }
        if (str[begin] == '-') sign = -1;
        if (str[begin] == '+' || str[begin] == '-') ++begin;
        for (int idx = begin; idx < str.length(); ++idx) {
            if (str[idx] < '0' || str[idx] > '9') break;
            int num = str[idx] - '0';
            if (ans > boundary || ans == boundary && num > 7) {
                return sign == -1 ? INT32_MIN : INT32_MAX;
            }
            ans = ans * 10 + num;
        }
        return sign * ans;
    }
};