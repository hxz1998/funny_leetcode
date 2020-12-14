/**
 * Created by Xiaozhong on 2020/12/14.
 * Copyright (c) 2020/12/14 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        // 确保最后一个单词也能触发转换
        S.push_back(' ');
        // 用来存储每一个单词的缓冲器
        string buf;
        // 最后需要拼接的后缀
        string suffix = "a";
        // 返回值
        string ans;
        // 对 S 中的每一个字符进行遍历
        for (char c : S) {
            // 如果不是空格，那么就追加到缓冲区中
            if (c != ' ') {
                buf.push_back(c);
            } else if (buf != "") {
                // 如果遇到了空格，而且当前缓冲区不为空，那么就进来转换
                // 首先记录下来第一个字符
                char front = buf.front();
                // 如果不是元音字符情况，那么就把第一个字符放到原字符串末尾
                if (front != 'a' && front != 'e' && front != 'i' && front != 'o' && front != 'u'
                    && front != 'A' && front != 'E' && front != 'I' && front != 'O' && front != 'U') {
                    buf = buf.substr(1);
                    buf.push_back(front);
                }
                // 缓冲区拼接 ma 和 后缀
                buf.append("ma").append(suffix);
                // 返回值拼接 缓冲区 和空格
                ans.append(buf).push_back(' ');
                // 清空缓冲区
                buf = "";
                // 更新后缀
                suffix.push_back('a');
            }
        }
        // 记得把最后一个空格删掉 :-) 大功告成！
        return ans.substr(0, ans.size() - 1);
    }
};