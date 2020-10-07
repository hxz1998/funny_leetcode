/**
 * Created by Xiaozhong on 2020/9/11.
 * Copyright (c) 2020/9/11 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> count;
        for (auto c : s) count[c]++;
        vector<int> split;
        for (int i = 0; i < s.size(); ++i) if (count[s[i]] < k) split.push_back(i);
        if (split.size() == 0) return s.length();
        split.push_back(s.length());
        int ans = 0, start = 0;
        for (int i = 0; i < split.size(); ++i) {
            int len = split[i] - start;
            if (len > ans) ans = max(ans, longestSubstring(s.substr(start, len), k));
            start = split[i] + 1;
        }
        return ans;
    }
};