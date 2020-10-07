/**
 * Created by Xiaozhong on 2020/9/22.
 * Copyright (c) 2020/9/22 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        if (nums.size() == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) ans.push_back(nums[i++]);
        }
        return ans;
    }
};
