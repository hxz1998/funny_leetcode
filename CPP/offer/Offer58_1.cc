/**
 * Created by Xiaozhong on 2021/12/21.
 * Copyright (c) 2021/12/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
private:
    vector<string> split(const string &str) {
        int idx = 0;
        while (idx < str.size() && str[idx] == ' ') ++idx;
        vector<string> ans;
        string buffer;
        while (idx < str.size()) {
            if (str[idx] == ' ' && buffer.size() > 0) {
                ans.emplace_back(buffer);
                buffer = "";
            } else if (str[idx] != ' ') buffer.push_back(str[idx]);
            idx++;
        }
        if (buffer.size() > 0) ans.emplace_back(buffer);
        return ans;
    }

public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        vector<string> words = split(s);
        if (words.empty()) return "";
        string ans;
        for (int idx = words.size() - 1; idx > 0; --idx) {
            ans += words[idx] + ' ';
        }
        ans += words.front();
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("the sky is blue");
}