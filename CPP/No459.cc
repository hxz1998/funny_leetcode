/**
 * Created by Xiaozhong on 2020/9/27.
 * Copyright (c) 2020/9/27 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.length();
    }
};

int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("abcdabcd") << endl;
    cout << s.repeatedSubstringPattern("abc") << endl;
}