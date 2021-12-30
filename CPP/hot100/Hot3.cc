/*
 * Created by Xiaozhong on 12/30/2021.
 * Copyright (c) 12/30/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int left = 0, right = 0;
        int ans = 0;
        unordered_set<char> uSet;
        while (right < s.length()) {
            while (right < s.length() && uSet.find(s[right]) == uSet.end()) uSet.insert(s[right++]);
            ans = max(ans, right - left);
            while (left < right && uSet.find(s[right]) != uSet.end()) uSet.erase(s[left++]);
        }
        return ans;
    }
};