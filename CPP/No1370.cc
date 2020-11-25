/**
 * Created by Xiaozhong on 2020/11/25.
 * Copyright (c) 2020/11/25 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        vector<int> counter(26, 0);
        for (const char &c : s) ++counter[c - 'a'];
        string ret = "";
        while (ret.length() < s.length()) {
            for (int i = 0; i < 26; ++i) {
                if (counter[i] > 0) {
                    ret.push_back(i + 'a');
                    --counter[i];
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (counter[i] > 0) {
                    ret.push_back(i + 'a');
                    --counter[i];
                }
            }
        }
        return ret;
    }
};