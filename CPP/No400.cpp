/**
 * Created by Xiaozhong on 2020/9/13.
 * Copyright (c) 2020/9/13 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long base = 9, digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            ++digits;
        }

        int idx = n % digits;
        if (idx == 0) idx = digits;
        long number = 1;
        for (int i = 1; i < digits; ++i) number *= 10;
        number += (idx == digits) ? n / digits - 1 : n / digits;

        for (int i = idx; i < digits; ++i) number /= 10;
        return number % 10;
    }
};

int main() {
    Solution s;
    cout << s.findNthDigit(365) << endl;
}