/**
 * Created by Xiaozhong on 2020/11/4.
 * Copyright (c) 2020/11/4 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                n /= d;
                ans += d;
            }
            ++d;
        }
        return ans;
    }
};