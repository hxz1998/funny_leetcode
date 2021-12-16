/*
 * Created by Xiaozhong on 12/13/2021.
 * Copyright (c) 12/13/2021 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int base = 9, digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits++;
        }
        int idx = n % digits;
        if (idx == 0) idx = digits;
        int number = 1;
        for (int i = 1; i < digits; ++i) number *= 10;
        number += (idx == digits) ? n / digits - 1 : n / digits;
        for (int i = idx; i < digits; ++i) number /= 10;
        return number % 10;
    }
};

int main() {
    Solution s;
    cout << s.findNthDigit(11) << endl;
}