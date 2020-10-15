/**
 * Created by Xiaozhong on 2020/10/15.
 * Copyright (c) 2020/10/15 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
    void reverse(string &s, int begin, int end) {
        while (begin < end) {
            char t = s[begin];
            s[begin] = s[end];
            s[end] = t;
            begin++;
            end--;
        }
    }

public:
    string reverseStr(string s, int k) {
        for (auto iter = 0; iter < s.length(); iter += 2 * k) {
            int begin = iter;
            // 关键在下面这句获取结尾下标的计算
            int end = min(iter + k - 1, (int) s.length() - 1);
            reverse(s, begin, end);
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseStr("abcdefg", 2);
}