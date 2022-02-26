/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int num: nums) ans ^= num;
        return ans;
    }
};