/**
 * Created by Xiaozhong on 2020/11/25.
 * Copyright (c) 2020/11/25 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string> &source) {
        vector<string> ans;
        bool in_block = false;
        string buffer;
        for (const string &line : source) {
            int idx = 0;
            if (!in_block) buffer = "";
            while (idx < line.length()) {
                if (!in_block && idx + 1 < line.length() && line[idx] == '/' && line[idx + 1] == '*') {
                    in_block = true;
                    ++idx;
                } else if (in_block && idx + 1 < line.length() && line[idx] == '*' && line[idx + 1] == '/') {
                    in_block = false;
                    ++idx;
                } else if (!in_block && idx + 1 < line.length() && line[idx] == '/' && line[idx + 1] == '/') {
                    break;
                } else if (!in_block) {
                    buffer.push_back(line[idx]);
                }
                idx++;
            }
            if (!in_block && !buffer.empty()) ans.emplace_back(buffer);
        }
        return ans;
    }
};