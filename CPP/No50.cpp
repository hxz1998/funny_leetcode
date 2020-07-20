/**
 * Created by Xiaozhong on 2020/7/20.
 * Copyright (c) 2020/7/20 Xiaozhong. All rights reserved.
 */

#include <iostream>

using namespace std;

class Solution {
private:
    double quickMul(double x, long n) {
        // 递归结束条件
        if (n == 0) {
            return 1.0;
        }
        // 递归，计算 x^n 可以先计算 x^(n/2)
        double y = quickMul(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }

public:

    double myPow(double x, int n) {
        long N = n;
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

int main(int argc, char **args) {
    Solution s;
    cout << s.myPow(2, -2) << endl;

}