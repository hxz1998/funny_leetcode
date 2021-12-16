/*
 * Created by Xiaozhong on 12/13/2021.
 * Copyright (c) 12/13/2021 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0, curr = INT32_MAX;
        for (int num: nums) {
            if (cnt == 0) {
                cnt += 1;
                curr = num;
            } else {
                cnt += curr == num ? 1 : -1;
            }
        }
        return curr;
    }
};