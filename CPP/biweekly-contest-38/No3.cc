/**
 * Created by Xiaozhong on 2020/10/31.
 * Copyright (c) 2020/10/31 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        int m = s.size(), n = t.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = 0;
                for (int k = 0; i + k < m && j + k < n; ++k) {
                    diff += (s[i + k] != t[j + k]);
                    if (diff > 1) break;
                    if (diff == 1) ++ans;
                }
            }
        }
        return ans;
    }
};