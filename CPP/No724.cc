/**
 * Created by Xiaozhong on 2020/11/25.
 * Copyright (c) 2020/11/25 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        size_t sz = nums.size();
        int sum = 0, left_sum = 0;
        for (auto i : nums) sum += i;
        for (int i = 0; i < sz; ++i) {
            if (sum - nums[i] - left_sum == left_sum) return i;
            else left_sum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << s.pivotIndex(nums) << endl;
}