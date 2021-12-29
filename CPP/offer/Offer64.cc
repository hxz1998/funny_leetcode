/**
 * Created by Xiaozhong on 2021/12/28.
 * Copyright (c) 2021/12/28 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};