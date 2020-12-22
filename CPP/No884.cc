/**
 * Created by Xiaozhong on 2020/12/22.
 * Copyright (c) 2020/12/22 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        A.push_back(' ');
        unordered_map<string, int> counter;
        string buf;
        for (char c : A) {
            if (c == ' ') {
                counter[buf]++;
                buf.clear();
            } else buf.push_back(c);
        }
        B.push_back(' ');
        for (char c : B) {
            if (c == ' ') {
                counter[buf]++;
                buf = "";
            } else buf.push_back(c);
        }
        vector<string> ans;
        for (auto iter = counter.begin(); iter != counter.end(); ++iter) {
            if (iter->second == 1) ans.emplace_back(iter->first);
        }
        return ans;
    }
};