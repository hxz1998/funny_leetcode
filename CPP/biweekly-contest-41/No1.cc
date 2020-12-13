/**
 * Created by Xiaozhong on 2020/12/12.
 * Copyright (c) 2020/12/12 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string> &words) {
        vector<int> mapper(26, 0);
        for (char c : allowed) mapper[c - 'a'] = 1;
        int ans = 0;
        for (const string &word : words) {
            int idx = 0;
            for (; idx < word.length(); ++idx) {
                if (!mapper[word[idx] - 'a']) break;
            }
            if (idx == word.length()) ++ans;
        }
        return ans;
    }
};