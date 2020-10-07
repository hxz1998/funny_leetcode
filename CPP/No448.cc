/**
 * Created by Xiaozhong on 2020/9/23.
 * Copyright (c) 2020/9/23 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            nums[abs(nums[i]) - 1] = (nums[abs(nums[i]) - 1] > 0 ? -nums[abs(nums[i]) - 1] : nums[abs(nums[i]) - 1]);
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i - 1] > 0) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    for (int i : s.findDisappearedNumbers(nums)) cout << i << " ";
}