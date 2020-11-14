/**
 * Created by Xiaozhong on 2020/11/14.
 * Copyright (c) 2020/11/14 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int calPoints(vector<string> &ops) {
        stack<int> stk;
        for (string &c : ops) {
            if (c == "+") {
                int first, second;
                first = stk.top();
                stk.pop();
                second = stk.top();
                stk.push(first);
                stk.push(first + second);
            } else if (c == "D") {
                int first = stk.top();
                stk.push(first * 2);
            } else if (c == "C") {
                stk.pop();
            } else {
                stk.push(stoi(c));
            }
        }
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> ops = {
            "5", "2", "C", "D", "+"
    };
    cout << s.calPoints(ops) << endl;
}