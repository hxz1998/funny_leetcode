/**
 * Created by Xiaozhong on 2022/1/26.
 * Copyright (c) 2022/1/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

/**
 * 正数除以正数   正常
 * 正数除以负数   可能溢出，负数是一个 INT32_MIN
 * 负数除以正数   可能溢出，
 * 负数除以负数   可能溢出
 */
class Solution {
public:
    int divide(int a, int b) {
        if (a == INT32_MIN && b == -1) return INT32_MAX;
        int sign = a < 0 && b > 0 || a > 0 && b < 0 ? -1 : 1;
        a = a < 0 ? a : -a;
        b = b < 0 ? b : -b;
        unsigned int ret = helper(a, b);
        return sign < 0 ? -ret : ret;
    }

private:
    unsigned int helper(int a, int b) {
        unsigned int ret = 0;
        while (a <= b) {
            int tmp = b;
            unsigned int cnt = 1;
            while (tmp >= 0xc0000000 && a <= tmp + tmp) {
                tmp += tmp;
                cnt += cnt;
            }
            ret += cnt;
            a -= tmp;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.divide(15, 2) << endl;
    cout << s.divide(7, -3) << endl;
    cout << s.divide(INT32_MIN, 1) << endl;
}