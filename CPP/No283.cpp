/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_no_zero = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) nums[last_no_zero++] = nums[i];
        }
        while (last_no_zero < n) nums[last_no_zero++] = 0;
    }
};

int main() {
    vector<int> nums = {0, 1, 3, 0, 2};
    Solution s;
    s.moveZeroes(nums);
    for (int i : nums) {
        cout << i << " ";
    }
}