/**
 * Created by Xiaozhong on 2020/7/15.
 * Copyright (c) 2020/7/15 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string tmp = "1";
        string ans = "";
        map<string, int> mapper;
        for (int i = 1; i < n + 1; ++i) {   // 实际上是从 2 开始构造的
            char current_idx = tmp[0];  // 记录第一个字符
            mapper[to_string(current_idx)] = 1; // 将第一个字符初始化为出现了 1 次
            for (int j = 1; j < tmp.length(); j++) {    // 遍历当前产生的字符串每一位
                if (tmp[j] == tmp[j - 1]) {             // 如果当前字符和前一位字符相同，那么就把当前字符出现次数 + 1
                    mapper[to_string(current_idx)]++;
                } else {                                // 否则就把缓冲区给写入到 ans 返回值中
                    for (std::map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++) {
                        ans += to_string(mapper[it->first]);
                        ans += to_string(stoi(it->first) - '0');
                    }
                    current_idx = tmp[j];
                    mapper.clear();
                }
            }
            tmp = ans;
            for (std::map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++) {
                tmp += to_string(mapper[it->first]);
                tmp += to_string(stoi(it->first) - '0');
            }
            mapper.clear();
        }
        ans = tmp;
        return ans;
    }
};

int main(int argc, char *args[]) {
    Solution s;
    cout << s.countAndSay(2) << endl;
    map<string, int> mapper;
    mapper["a"] = 1;
    mapper["b"] = 2;
    mapper["a"] = 3;
    string tmp;
    for (std::map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++) {
        tmp += to_string(mapper[it->first]);
        tmp += it->first;
    }
    cout << tmp << endl;
}
