/**
 * Created by Xiaozhong on 2020/12/11.
 * Copyright (c) 2020/12/11 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        for (auto &item : cpdomains) {
            int idx = item.find(' ');
            int num = stoi(item.substr(0, idx));
            string dmname = item.substr(idx + 1);
            while (idx > 0) {
                cnt[dmname] += num;
                idx = dmname.find('.');
                dmname = dmname.substr(idx + 1);
            }
        }
        for (auto &item : cnt) ans.emplace_back(to_string(item.second) + " " + item.first);
        return ans;
    }
};