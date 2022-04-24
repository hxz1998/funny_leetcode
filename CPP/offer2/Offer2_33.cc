/**
 * Created by Xiaozhong on 2022/4/6.
 * Copyright (c) 2022/4/6 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

class Solution {
    string helper(string word) {
        sort(word.begin(), word.end());
        return word;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mapper;
        for (const string &str : strs) {
            mapper[helper(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            ans.push_back(iter->second);
        }
        return ans;
    }
};
