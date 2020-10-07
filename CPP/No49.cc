/**
 * Created by Xiaozhong on 2020/7/20.
 * Copyright (c) 2020/7/20 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        // 创建映射表
        map<string, vector<string>> mapper;

        // 首先拷贝一个字符串的备份，然后对这个备份进行排序操作
        // 排序的结果作为 键（key） 来存储，其 值（value） 为排序前的字符串。
        for (const string &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mapper[t].push_back(s);
        }
        // 最后将每一个值取出来放入返回值中
        for (pair<string, vector<string>> s : mapper) {
            ans.push_back(s.second);
        }
        return ans;
    }
};

int main(int argc, char *args[]) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for (vector<string> item : ans) {
        for (string s : item) {
            cout << s << " ";
        }
        cout << endl;
    }
}