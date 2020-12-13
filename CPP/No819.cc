/**
 * Created by Xiaozhong on 2020/12/12.
 * Copyright (c) 2020/12/12 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        paragraph.push_back('.');
        unordered_set<string> container;
        // 将不允许出现的单词放到集合中，方便查找
        for (string &item : banned) container.insert(item);
        unordered_map<string, int> mapper;
        string buf;
        for (char c : paragraph) {
            // 首先忽略大小写字符
            if (c <= 'z' && c >= 'a') {
                buf.push_back(c);
            } else if (c <= 'Z' && c >= 'A') {
                buf.push_back(c + 32);
            } else if (buf.length() > 0) {
                // 触发个数统计操作，先检查是否在禁用单词列表中
                if (container.count(buf) == 0) mapper[buf]++;
                buf = "";
            }
        }
        string ans;
        int mx = 0;
        // 找出出现次数最多的单词
        for (auto item : mapper) {
            if (item.second > mx) {
                mx = item.second;
                ans = item.first;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> banned = {"hit"};
    cout << s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", banned) << endl;
}