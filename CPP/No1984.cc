/**
 * Created by Xiaozhong on 2022/2/11.
 * Copyright (c) 2022/2/11 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1) return 0;
        int ans = INT32_MAX;
        for (int idx = 0; idx <= nums.size() - k; ++idx) {
            ans = min(ans, nums[idx + k - 1] - nums[idx]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {9, 4, 1, 7};
    cout << s.minimumDifference(nums, 2) << endl;
}