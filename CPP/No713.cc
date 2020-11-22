/**
 * Created by Xiaozhong on 2020/11/22.
 * Copyright (c) 2020/11/22 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) return 0;
        int product = 1, ans = 0, left = 0, right = 0;
        for (; right < nums.size(); ++right) {
            product *= nums[right];
            while (product >= k) product /= nums[left++];
            ans += (right - left + 1);
        }
        return ans;
    }
};