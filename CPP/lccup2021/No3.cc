/**
 * Created by Xiaozhong on 2021/4/5.
 * Copyright (c) 2021/4/5 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int magicTower(vector<int> &nums) {
        long long cut = 0;
        int life = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (-nums[i] > life) cut += nums[i];
            else life += nums[i];
        }
        return
    }
};