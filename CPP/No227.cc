/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "string"
#include "stack"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ans = 0, n = 0; // ans 记录最终的计算答案， n 用来将 "123" 转换为 123
        char sign = '+';    // 最初的符号，从左到右肯定是 + 开头呀
        stack<int> stack;   // 计算栈
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {   // 字符到数字的转换过程
                n = n * 10 + (s[i] - '0');
            }
            if (s[i] < '0' && s[i] != ' ' || i == s.length() - 1) {
                int pre;        // 再下面用来记录前一个数字
                switch (sign) {
                    case '+':   // 如果是 + ，那么就直接添加进来
                        stack.push(n);
                        break;
                    case '-':   // 如果是 - ，那么就添加一个负数
                        stack.push(-n);
                        break;
                    case '*':   // 如果是 * ，那么就将栈顶元素相乘，然后再放回来
                        pre = stack.top();
                        stack.pop();
                        stack.push(pre * n);
                        break;
                    case '/':   // 如果是 / ，那么就将栈顶元素相除，再放回来
                        pre = stack.top();
                        stack.pop();
                        stack.push(pre / n);
                        break;
                }
                sign = s[i];    // 记录符号
                n = 0;          // 清空当前转换的数字
            }
        }
        while (!stack.empty()) {    // 最后把栈里面的数字挨个加起来
            ans += stack.top();
            stack.pop();
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.calculate("3+2*2") << endl;
}