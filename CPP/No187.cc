/**
 * Created by Xiaozhong on 2020/8/18.
 * Copyright (c) 2020/8/18 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mapper;
        vector<string> ans;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string tmp = s.substr(i, 10);
            if (mapper[tmp] == 1) ans.push_back(tmp);
            mapper[tmp]++;
        }
        return ans;
    }
};