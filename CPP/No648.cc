/**
 * Created by Xiaozhong on 2020/11/3.
 * Copyright (c) 2020/11/3 Xiaozhong. All rights reserved.
 */
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
    vector<string> split(string str, const char delimiter) {
        vector<string> res;
        string buffer = "";
        for (char c : str) {
            if (c != delimiter) buffer.push_back(c);
            else {
                res.push_back(buffer);
                buffer = "";
            }
        }
        res.push_back(buffer);
        return res;
    }

public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        unordered_set<string> rootset;
        for (const string &item : dictionary) rootset.insert(item);

        string ans;
        for (string &s : split(sentence, ' ')) {
            string prefix;
            for (int i = 1; i <= s.size(); ++i) {
                prefix = s.substr(0, i);
                if (rootset.count(prefix)) break;
            }
            if (ans.length() > 0) ans.push_back(' ');
            ans.append(prefix);
        }
        return ans;
    }
};