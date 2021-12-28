/**
 * Created by Xiaozhong on 2021/12/28.
 * Copyright (c) 2021/12/28 Xiaozhong. All rights reserved.
 */

#include "iostream"

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int c = (unsigned int) (a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};