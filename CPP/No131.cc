/**
 * Created by Xiaozhong on 2020/8/8.
 * Copyright (c) 2020/8/8 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
private:
    // 双指针法检查字符串 s 是否是回文
    bool check(string s) {
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    // 回溯法，对字符串 s 进行处理
    void backtrace(string &s, vector<vector<string>> &ans, vector<string> &path, int start) {
        // 遍历到结束了，就把结果放到结果集中
        if (start >= s.length()) {
            ans.emplace_back(path);
            return;
        }
        // 从 start 开始回溯检查子字符串 s[start-end]
        for (int i = start; i < s.length(); i++) {
            // 如果不是回文，那就没得说了
            if (!check(s.substr(start, i - start + 1))) continue;
            // 是回文，那就先把结果放到结果集中，再继续对子字符串进行处理
            path.push_back(s.substr(start, i - start + 1));
            backtrace(s, ans, path, i + 1);
            // 回溯！
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> buffer;
        backtrace(s, ans, buffer, 0);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> ans;
    ans = s.partition("aab");
    for (vector<string> item: ans) {
        for (string str: item) {
            cout << str << " ";
        }
        cout << endl;
    }
}
