/**
 * Created by Xiaozhong on 2020/12/20.
 * Copyright (c) 2020/12/20 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        // ans 用来返回，buf 用来把原来数据中的数字保存
        string ans, buf;
        // 对所有数字保存下来
        for (char c : number) if (c != ' ' && c != '-') buf.push_back(c);
        // 对缓冲区中的数据进行挨个分组处理
        for (int i = 0; i < buf.size(); ++i) {
            // 如果遇到分割边界，而且不是开头和末尾的特殊情况，那么就直接拼接分隔符 -
            if (i != 0 && i % 3 == 0 && buf.size() - i > 1) {
                ans.push_back('-');
            } else if (i != 0 && i % 3 == 0 && i == buf.size() - 1) {
                // 否则就修改最后的两组数据
                char c = ans.back();
                ans.pop_back();
                ans.push_back('-');
                ans.push_back(c);
            }
            ans.push_back(buf[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.reformatNumber("1-23-45 6") << endl;
    cout << s.reformatNumber("123 4-567") << endl;
    cout << s.reformatNumber("--17-5 229 35-39475 ") << endl;
}