/**
 * Created by Xiaozhong on 2020/9/27.
 * Copyright (c) 2020/9/27 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "algorithm"
#include "cmath"

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(states));
    }
};