/**
 * Created by Xiaozhong on 2020/10/30.
 * Copyright (c) 2020/10/30 Xiaozhong. All rights reserved.
 */
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; ++i) {
            double b = sqrt(c - i * i);
            if (b == (int) b) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.judgeSquareSum(5);
}