/**
 * Created by Xiaozhong on 2020/10/29.
 * Copyright (c) 2020/10/29 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // 按照指定字符切分字符串
    vector<string> split(const string &s, const char delimiter) {
        vector<string> ret;
        string buf;
        for (const char &c : s) {
            if (c != delimiter) buf.push_back(c);
            else {
                ret.emplace_back(buf);
                buf = "";
            }
        }
        if (!buf.empty()) ret.emplace_back(buf);
        return ret;
    }

    // 文件名和括号内的内容抽取出来
    vector<string> extractContent(const string &s) {
        vector<string> ret;
        string buf;
        for (const char &c : s) {
            if (c == '(' || c == ')') {
                ret.emplace_back(buf);
                buf = "";
            } else {
                buf.push_back(c);
            }
        }
        if (!buf.empty()) ret.emplace_back(buf);
        return ret;
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        unordered_map<string, vector<string>> mapper;
        for (const string &path : paths) {
            // 第一个是路径名，后面的是文件名+内容
            vector<string> ret = split(path, ' ');
            for (int i = 1; i < ret.size(); ++i) {
                vector<string> fnAndCt = extractContent(ret[i]);
                mapper[fnAndCt[1]].emplace_back(ret[0] + "/" + fnAndCt[0]);
            }
        }
        vector<vector<string>> ans;
        for (auto &item : mapper) {
            if (item.second.size() >= 2) ans.emplace_back(item.second);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> paths = {
            "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"
    };
    s.findDuplicate(paths);
}