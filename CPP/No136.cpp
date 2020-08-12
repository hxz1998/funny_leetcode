/**
 * Created by Xiaozhong on 2020/8/12.
 * Copyright (c) 2020/8/12 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int i : nums) ans = ans ^ i;
        return ans;
    }
};
