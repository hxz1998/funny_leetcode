/**
 * Created by Xiaozhong on 2020/9/9.
 * Copyright (c) 2020/9/9 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mapper;
        for (char c : s) {
            mapper[c]++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (mapper[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqChar("leetcode") << endl;
}