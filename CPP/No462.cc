/**
 * Created by Xiaozhong on 2020/9/27.
 * Copyright (c) 2020/9/27 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int count = 0, mid = nums[nums.size() / 2];
        for (int num : nums) {
            count += abs(num - mid);
        }
        return count;
    }
};