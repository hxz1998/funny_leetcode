/**
 * Created by Xiaozhong on 2020/11/18.
 * Copyright (c) 2020/11/18 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        map<string, int> mCounter;
        for (const auto word : words) mCounter[word]++;
        vector<pair<string, int>> vCounter;
        for (auto iter = mCounter.begin(); iter != mCounter.end(); ++iter) {
            vCounter.emplace_back(make_pair(iter->first, iter->second));
        }
        sort(vCounter.begin(), vCounter.end(), [](const pair<string, int> &rhs, const pair<string, int> &lhs) {
            return rhs.second == lhs.second ? rhs.first < lhs.first : rhs.second > lhs.second;
        });
        vector<string> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(vCounter[i].first);
        }
        return ans;
    }
};