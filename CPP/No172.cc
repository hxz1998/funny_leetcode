/**
 * Created by Xiaozhong on 2020/8/18.
 * Copyright (c) 2020/8/18 Xiaozhong. All rights reserved.
 */

#include "iostream"

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};