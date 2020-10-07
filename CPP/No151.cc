/**
 * Created by Xiaozhong on 2020/8/15.
 * Copyright (c) 2020/8/15 Xiaozhong. All rights reserved.
 */

#include "string"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size(), index = 0;
        for (int start = 0; start < n; start++) {
            if (s[start] != ' ') {
                if (index != 0) s[index++] = ' ';   // 单词开头补上空格
                int end = start;                    // 调整单词结束的指针，开始定位单词结束的地方
                while (end < n && s[end] != ' ') s[index++] = s[end++]; // 拷贝字符，目的是消除掉空格
                reverse(s.begin() + index - (end - start), s.begin() + index);  // 翻转单词的字符
                start = end;                        // 开始处理下一个单词
            }
        }
        s.erase(s.begin() + index, s.end());        //擦除掉剩余的空格
        return s;
    }
};

int main() {
    Solution s;
    string ans = s.reverseWords("  Hello, World!  n!!");
    cout << ans << endl;
}