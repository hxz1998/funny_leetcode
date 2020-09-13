/**
 * Created by Xiaozhong on 2020/9/13.
 * Copyright (c) 2020/9/13 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // base 代表每一个数值域的范围 例如 0-9 10-90，digits代表了它应该出现在几位数中
        long base = 9, digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            ++digits;
        }

        // 经过上面的计算，现在的 n 已经成了有 digits 位数的第 n 个数
        int idx = n % digits;   // 求出它在第 n 个数中应该在第 idx 位出现
        if (idx == 0) idx = digits; // 如果没有余数，那么说明它就是最后一位
        long number = 1;        // 拼接出来原来的数
        for (int i = 1; i < digits; ++i) number *= 10;
        number += (idx == digits) ? n / digits - 1 : n / digits; // 补齐最后一位

        for (int i = idx; i < digits; ++i) number /= 10;
        return number % 10;
    }
};

int main() {
    Solution s;
    cout << s.findNthDigit(365) << endl;
}