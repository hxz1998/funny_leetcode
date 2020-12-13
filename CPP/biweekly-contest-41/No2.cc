/**
 * Created by Xiaozhong on 2020/12/12.
 * Copyright (c) 2020/12/12 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
        int sz = nums.size();
        // 建立一个用于存放结果的数组
        vector<int> result(sz, 0);
        // 记录左和与右和
        vector<int> left_sum(sz, 0), right_sum(sz, 0);
        // 求左和
        for (int i = 0; i < sz; ++i) {
            if (i == 0) left_sum[i] = nums[i];
            else left_sum[i] = (left_sum[i - 1] + nums[i]);
        }
        // 求右和
        for (int j = sz - 1; j >= 0; --j) {
            if (j == sz - 1) right_sum[j] = nums[j];
            else right_sum[j] = (right_sum[j + 1] + nums[j]);
        }
        // 更新返回值，更新算法：
        // n 个 nums[i] 与左和之差 + (sz - n) 个 nums[i] 与右和之差
        for (int i = 0; i < sz; ++i) {
            result[i] = (i + 1) * nums[i] - left_sum[i] + right_sum[i] - (sz - i) * nums[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 5};
    vector<int> ans = s.getSumAbsoluteDifferences(nums);
    return 0;
}