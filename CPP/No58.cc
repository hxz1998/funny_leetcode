/**
 * Created by Xiaozhong on 2020/7/21.
 * Copyright (c) 2020/7/21 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // 空字符串当然直接返回 0
        if (s.empty()) return 0;
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {      // 如果匹配到了字母，那么就直接加一
                ans++;
            } else if (ans == 0) {  // 当匹配到了空格，而且长度仍然为 0 的话，很有可能是末尾有一个空格，需要跳过它
                continue;
            } else {                //返回最终答案
                return ans;
            }
        }
        return ans;
    }
};

int main(int argc, char **args) {
    string str = "a";
    Solution s;
    cout << s.lengthOfLastWord(str);
}

/*
 * 这个解法竟然有问题! ( •̀ .̫ •́ )✧ 在我的机器上跑的是 1，在人家官方的机器上跑出来是 0
 * 原因找到啦！人家输入的是：a_ [_代表空格]，那么应该输出 1
 */
//class Solution {
//public:
//    int lengthOfLastWord(string s) {
//        if (s.empty()) return 0;
//        vector<string> ans = split(s, " ");
//        return ans[ans.size() - 1].size();
//    }
//
//private:
//    vector<string> split(const string &str, const string &pattern) {
//        vector<string> ans;
//        if (str == "") return ans;
//
//        string strs = str + pattern;
//        int pos = strs.find(pattern);
//        while (pos != strs.npos) {
//            string temp = strs.substr(0, pos);
//            ans.push_back(temp);
//            strs = strs.substr(pos + 1, strs.size());
//            pos = strs.find(pattern);
//        }
//        return ans;
//    }
//};