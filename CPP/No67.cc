/**
 * Created by Xiaozhong on 2020/7/23.
 * Copyright (c) 2020/7/23 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        // 首先把序列反过来，这样好从 0 作为低位开始处理
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        // 记录下两者的最长长度，并且设置进位位 = 0
        int n = max(a.size(), b.size()), carry = 0;
        for (int i = 0; i < n; ++i) {
            // 如果当前下标没有越界，那么就加上该值，否则就加上 0
            carry += i >= a.size() ? 0 : (a[i] == '1');
            carry += i >= b.size() ? 0 : (b[i] == '1');
            // 当前值 = (carry + a + b) % 2，如果为 2 的整数倍，那么就进位一下然后用 0，否则就直接用 1
            ans.push_back((carry % 2) ? '1' : '0');
            // 把进位位更新了
            carry /= 2;
        }
        // 如果进位位没有处理完，那么就在末尾补 0（实际上是最高位）
        if (carry) ans.push_back('1');
        // 把最终答案翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string a = "11";
    string b = "1";
    Solution s;
    string ans = s.addBinary(a, b);
    cout << ans;
}