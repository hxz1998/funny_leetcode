/**
 * Created by Xiaozhong on 2022/3/20.
 * Copyright (c) 2022/3/20 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
    bool less(const string &lhs, const string &rhs, const unordered_map<char, int> &mapper) {
        int sz = min(lhs.size(), rhs.size());
        for (int idx = 0; idx < sz; ++idx) {
            if (mapper.at(lhs[idx]) < mapper.at(rhs[idx])) return true;
            if (mapper.at(lhs[idx]) > mapper.at(rhs[idx])) return false;
        }
        return lhs.size() < rhs.size();
    }

public:
    bool isAlienSorted(vector<string> &words, string order) {
        unordered_map<char, int> mapper;
        for (int idx = 0; idx < order.size(); ++idx) mapper[order[idx]] = idx;
        for (int idx = 1; idx < static_cast<int>(words.size()); ++idx) {
            if (!less(words[idx - 1], words[idx], mapper)) return false;
        }
        return true;
    }
};