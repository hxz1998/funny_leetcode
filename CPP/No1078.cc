/**
 * Created by Xiaozhong on 2021/12/26.
 * Copyright (c) 2021/12/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
private:
    // 按照指定字符切分字符串
    vector<string> split(const string &s, const char delimiter) {
        vector<string> ret;
        string buf;
        for (const char &c: s) {
            if (c != delimiter) buf.push_back(c);
            else {
                ret.emplace_back(buf);
                buf = "";
            }
        }
        if (!buf.empty()) ret.emplace_back(buf);
        return ret;
    }

public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words = split(text, ' ');
        vector<string> ans;
        for (int i = 2; i < words.size(); ++i) {
            if (words[i - 2] == first && words[i - 1] == second) ans.emplace_back(words[i]);
        }
        return ans;
    }
};