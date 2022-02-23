/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int maxDistance = 0;
        int n = nums.size();
        if (n == 1) return true;
        for (int idx = 0; idx < n; ++idx) {
            if (maxDistance <= idx && nums[idx] == 0) return false;
            maxDistance = max(maxDistance, nums[idx] + idx);
            if (maxDistance >= n - 1) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.canJump(nums) << endl;
    nums = {3, 2, 1, 0, 4};
    cout << s.canJump(nums) << endl;
}