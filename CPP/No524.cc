/**
 * Created by Xiaozhong on 2020/10/11.
 * Copyright (c) 2020/10/11 Xiaozhong. All rights reserved.
 */
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    // 从 lhs 中删除某些字符，来匹配 rhs
    bool check(const string &lhs, const string &rhs) {
        // 双指针法，pl 指向 lhs 中的位置，pr 指向 rhs 中的位置
        int pl = 0, pr = 0;
        for (; pl < lhs.size() && pr < rhs.size(); ++pl) {
            if (lhs[pl] == rhs[pr]) ++pr;
        }
        // 看看是否到了 rhs 末端
        return pr == rhs.size();
    }

public:
    string findLongestWord(string s, vector<string> &d) {
        // 排序算法，首先按照长度降序排序，然后按照字典序升序排序
        sort(d.begin(), d.end(), [](const string &lhs, const string &rhs) {
            return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() > rhs.size();
        });
        // 从长到短挨个检查
        for (int i = 0; i < d.size(); ++i) {
            if (check(s, d[i])) return d[i];
        }
        return "";
    }
};

int main() {
    Solution s;
    vector<string> d = {"ale", "apple", "monkey", "plea"};
    cout << s.findLongestWord("abpcplea", d);
}