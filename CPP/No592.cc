/**
 * Created by Xiaozhong on 2020/10/23.
 * Copyright (c) 2020/10/23 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // 根据 delimiter 来切分字符串
    vector<string> split(const string &s, char delimiter) {
        vector<string> ret;
        string buf;
        for (const char &c : s) {
            if (c != delimiter) buf.push_back(c);
            else {
                ret.emplace_back(buf);
                buf = "";
            }
        }
        ret.emplace_back(buf);
        return ret;
    }

    // 最小公倍数
    int lcm(int a, int b) { return a * b / gcd(a, b); }

    // 最大公约数
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

public:
    string fractionAddition(string expression) {
        vector<char> sign;
        // 首先记录下出现的符号，注意！需要从 1 开始而不是 0，跳过开始的负号（不是运算符）
        for (int i = 1; i < expression.length(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-') sign.emplace_back(c);
        }
        // 记录分子nums 和分母den
        vector<int> nums, den;
        for (const string &sub : split(expression, '+')) {
            for (const string &subsub : split(sub, '-')) {
                if (subsub.length() > 0) {
                    vector<string> fraction = split(subsub, '/');
                    nums.emplace_back(stoi(fraction[0]));
                    den.emplace_back(stoi(fraction[1]));
                }
            }
        }
        // 检查第一个是否是负号，如果是就转换一下
        if (expression.front() == '-') nums[0] = -nums[0];
        // 初始化最小公倍数
        int _lcm = 1;
        // 求出来分母的最小公倍数
        for (int x : den) _lcm = lcm(_lcm, x);
        // 通分运算
        int ans = _lcm / den[0] * nums[0];
        // 只计算分子的和，分母会被最小公倍数通分掉
        for (int i = 1; i < nums.size(); ++i) {
            if (sign[i - 1] == '+') ans += _lcm / den[i] * nums[i];
            else ans -= _lcm / den[i] * nums[i];
        }
        // 求答案 ans 和 最大公倍数（此时实际上是分母）的最小公约数，因为答案可能不是最简化
        int g = gcd(abs(ans), abs(_lcm));
        return to_string(ans / g) + "/" + to_string(_lcm / g);
    }
};

int main() {
    Solution s;
    cout << s.fractionAddition("-1/2+1/2") << endl;
}