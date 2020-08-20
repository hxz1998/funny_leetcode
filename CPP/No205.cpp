/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 如果两个字符串都是空的，那么就不用判断了呀~
        if (s.length() == 0 && t.length() == 0) return true;
        // 从左向右开始检查每一个字符，（以下标为研究对象）如果 s 中出现过但是在 t 中没有出现过，
        // 那么就说明前面的替换方法行不通，所以返回 false
        for (int i = 0; i < s.length(); i++) if (s.find(s[i]) != t.find(t[i])) return false;
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isIsomorphic("aab", "eeg") << endl;
}