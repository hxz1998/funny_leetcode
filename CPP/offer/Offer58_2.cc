/**
 * Created by Xiaozhong on 2021/12/21.
 * Copyright (c) 2021/12/21 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans = s.substr(n);
        for (int i = 0; i < n; ++i) ans.push_back(s[i]);
        return ans;
    }
};