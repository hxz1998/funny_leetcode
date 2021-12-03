/*
 * Created by Xiaozhong on 12/3/2021.
 * Copyright (c) 12/3/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }
        double ans = 1;
        while (nn > 0) {
            ans *= ((nn & 1) == 1) ? x : 1;
            x *= x;
            nn >>= 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.myPow(2, 10) << endl << s.myPow(2.1, 3) << endl;
}