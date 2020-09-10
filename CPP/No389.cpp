/**
 * Created by Xiaozhong on 2020/9/9.
 * Copyright (c) 2020/9/9 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        // 通过异或运算来对冗余字符删除，最后剩下的就是不成双的字符
        for (int i = 0; i < s.size(); ++i) t[0] ^= s[i];
        for (int i = 1; i < t.size(); ++i) t[0] ^= t[i];
        return t[0];
    }
};

int main() {
    Solution s;
    cout << s.findTheDifference("abcd", "abcde") << endl;
}