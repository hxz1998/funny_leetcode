/**
 * Created by Xiaozhong on 2020/9/24.
 * Copyright (c) 2020/9/24 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"
#include "algorithm"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mapper;
        for (char c : s) ++mapper[c];
        vector<pair<char, int>> vec;
        for (const pair<char, int> &item: mapper) {
            vec.push_back(item);
        }
        sort(vec.begin(), vec.end(), [](const pair<char, int> &v1, const pair<char, int> &v2) {
            return v1.second > v2.second;
        });
        string ans = "";
        for (auto &item : vec) {
            ans += string(item.second, item.first);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.frequencySort("afdjkaldf") << endl;
}