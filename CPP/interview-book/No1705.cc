/**
 * Created by Xiaozhong on 2021/11/7.
 * Copyright (c) 2021/11/7 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string> &array) {
        size_t n = array.size();
        vector<int> diff(n, 0);
        for (int idx = 0; idx < n; ++idx) {
            char c = array[idx][0];
            if (idx == 0) diff[idx] = isalpha(c) ? 1 : -1;
            else if (isalpha(c)) diff[idx] = diff[idx - 1] + 1;
            else diff[idx] = diff[idx - 1] - 1;
        }
        vector<int> scope(2, 0);
        unordered_map<int, int> mapper;
        mapper[0] = -1;
        for (int idx = 0; idx < n; ++idx) {
            if (mapper.find(diff[idx]) == mapper.end()) {
                mapper[diff[idx]] = idx;
            } else {
                int left = mapper[diff[idx]];
                int distance = idx - left;
                if (distance > scope[1] - scope[0]) {
                    scope[0] = left;
                    scope[1] = idx;
                }
            }
        }
        vector<string> ans;
        for (int idx = scope[0] + 1; idx <= scope[1]; ++idx) {
            ans.emplace_back(array[idx]);
        }
        return ans;
    }
};


ostream &operator<<(ostream &os, vector<string> &array) {
    for (string &item : array) os << item << " ";
    return os;
}

int main() {
    vector<string> array{"36", "86", "w", "17", "81", "W", "64", "97", "S", "s", "32", "61", "W", "I", "99", "X", "W",
                         "l", "33", "L", "17", "G", "27", "70", "37", "5", "62", "W", "x", "39", "58", "16", "Z", "46",
                         "X", "o", "45", "G", "63", "q", "16", "C", "E", "n", "w", "93", "35", "J", "L", "62", "11",
                         "95", "11", "7", "89", "c", "0", "41", "J", "X", "w", "41", "d", "62", "8", "65", "m", "K",
                         "85", "A", "V", "16", "92", "48", "35", "91", "18", "F", "13", "18", "p", "0", "88", "8", "5",
                         "75", "62", "83", "34", "27", "15", "79", "52", "r", "t", "49", "w", "G", "S", "18"};
    Solution solution;
    vector<string> ans = solution.findLongestSubarray(array);
    for (string &item : ans) {
        cout << item << " ";
    }
    return 0;
}