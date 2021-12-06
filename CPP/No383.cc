/**
 * Created by Xiaozhong on 2020/9/8.
 * Copyright (c) 2020/9/8 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "unordered_map"

using namespace std;

/*
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mapper;
        // 先对每一个字符建立映射，统计每个字符出现的次数
        for (char c : magazine) mapper[c]++;
        // 在对信息进行检查的时候，对每一个字符映射表里的数进行检查，如果不符合要求，则直接返回 false
        for (char c : ransomNote) {
            if (mapper[c] == 0) return false;
            mapper[c]--;
        }
        // 检查完成，直接返回 true
        return true;
    }
};*/
#include "vector"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> table(26, 0);
        for (char c: magazine) table[c - 'a']++;
        for (char c: ransomNote) if (table[c - 'a'] == 0) return false; else table[c - 'a']--;
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConstruct("aa", "aab") << endl;
}