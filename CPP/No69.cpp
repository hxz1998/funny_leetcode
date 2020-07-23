/**
 * Created by Xiaozhong on 2020/7/23.
 * Copyright (c) 2020/7/23 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int ans = exp(0.5 * log(x));
        return ((long long) (ans + 1) * (ans + 1)) <= x ? ans + 1 : ans;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(8);
}