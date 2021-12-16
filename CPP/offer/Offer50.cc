/*
 * Created by Xiaozhong on 12/14/2021.
 * Copyright (c) 12/14/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for (char c: s) cnt[c - 'a']++;
        for (char c: s) if (cnt[c - 'a'] == 1) return c;
        return ' ';
    }
};