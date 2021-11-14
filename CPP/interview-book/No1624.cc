/*
 * Created by Xiaozhong on 11/6/2021.
 * Copyright (c) 11/6/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<vector<int>> pairSums(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] > target) right--;
            else if (nums[left] + nums[right] < target) left++;
            else {
                left++;
                right--;
                ans.emplace_back(vector<int>{nums[left], nums[right]});
            }
        }
        return ans;
    }
};

