/**
 * Created by Xiaozhong on 2020/10/31.
 * Copyright (c) 2020/10/31 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
    vector<string> split(string str, const char delimiter) {
        vector<string> res;
        string buffer = "";
        for (char c : str) {
            if (c != delimiter) buffer.push_back(c);
            else {
                res.push_back(buffer);
                buffer = "";
            }
        }
        res.push_back(buffer);
        return res;
    }

public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> ans(n);
        stack<int> stk;     // 栈顶始终保存着正在执行的程序
        vector<string> s = split(logs[0], ':'); // 切分成 【id，start_end，timestamp】格式
        stk.push(stoi(s[0]));       // 先把第一个程序放进来
        int i = 1, prev = stoi(s[2]);   // prev 保存了前一个程序开始的时间戳
        while (i < logs.size()) {
            s = split(logs[i], ':');
            if (s[1] == "start") { // 如果是 start 类型，那么说明一个新程序开始了
                if (!stk.empty()) ans[stk.top()] += stoi(s[2]) - prev; // 先把前一个程序的执行时间算上
                stk.push(stoi(s[0]));   // 再把当前的程序入栈
                prev = stoi(s[2]);          // 记录当前程序的开始运行时间
            } else {
                ans[stk.top()] += stoi(s[2]) - prev + 1; // 说明程序结束了，那么就把时间累加上去
                stk.pop();  // 出栈
                prev = stoi(s[2]) + 1; // 下一个程序开始的时间，是当前结束时间的下一个时间
            }
            ++i;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> logs = {
            "0:start:0",
            "1:start:2",
            "1:end:5",
            "0:end:6"
    };
    vector<int> ans = s.exclusiveTime(2, logs);
    for (auto i : ans) cout << i << " ";
}