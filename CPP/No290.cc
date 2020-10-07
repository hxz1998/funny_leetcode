/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
private:
    // 根据空格来切分字符串
    vector<string> split(string str) {
        string buffer = "";
        vector<string> ans;
        for (char c : str) {
            if (c != ' ') buffer.push_back(c);
            else {
                ans.push_back(buffer);
                buffer = "";
            }
        }
        ans.push_back(buffer);
        return ans;
    }

public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs = split(str);
        if (pattern.length() != strs.size()) return false;
        unordered_map<char, string> c_s_mapper;
        unordered_map<string, char> s_c_mapper;
        for (int i = 0; i < pattern.size(); i++) {
            if (c_s_mapper.count(pattern[i])) { // 如果 字符到字符串 的映射中存在该键，那么就直接拿过来匹配
                if (c_s_mapper[pattern[i]] != strs[i]) return false;
            } else {                            // 否则就添加进 字符到字符串 的映射表中
                c_s_mapper[pattern[i]] = strs[i];
            }
            if (s_c_mapper.count(strs[i])) {    // 如果 字符串到字符的映射表中存在该键，那么就直接拿过来匹配
                if (s_c_mapper[strs[i]] != pattern[i]) return false;
            } else {                            // 否则就添加进 字符串到字符 的映射表中
                s_c_mapper[strs[i]] = pattern[i];
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
}