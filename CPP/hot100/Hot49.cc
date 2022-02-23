/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mapper;
        for (const string &item: strs) {
            mapper[covert(item)].emplace_back(item);
        }
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            ans.emplace_back(iter->second);
        }
        return ans;
    }

private:
    string covert(string str) {
        sort(str.begin(), str.end());
        return str;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    s.groupAnagrams(strs);
}