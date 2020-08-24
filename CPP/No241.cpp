/**
 * Created by Xiaozhong on 2020/8/24.
 * Copyright (c) 2020/8/24 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
private:
    // 判断是不是符号
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*';
    }

    // 根据符号计算两个值
    int calculate(int num1, char sign, int num2) {
        if (sign == '+') return num1 + num2;
        else if (sign == '-') return num1 - num2;
        else return num1 * num2;
    }

public:
    vector<int> diffWaysToCompute(string input) {
        int num = 0, index = 0;
        while (index < input.length() && isdigit(input[index])) num = num * 10 + input[index++] - '0';
        if (index == input.length()) return {num};  // 检查只有数字没有计算符号的情况
        vector<int> ans;
        for (int i = 0; i < input.length(); i++) {
            // 分治算法，分别计算 i 两边可能出现的值，然后合并到一起
            if (isOperator(input[i])) {
                // 计算前半部分可能出现的值
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                // 计算后半部分可能出现的值，之所以 + 1是因为要跳过计算符号
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
                for (int r1 : res1) {
                    for (int r2 : res2) {
                        // 使用符号 input[i] 来合并 r1 和 r2
                        ans.push_back(calculate(r1, input[i], r2));
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    string s = "123+45";
    cout << s.substr(0, 4) << endl;
    Solution solution;
    string s2 = "2-1-1";
    vector<int> ans = solution.diffWaysToCompute(s2);
    for (int i : ans) {
        cout << i << " ";
    }
}