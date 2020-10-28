/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include <cassert>
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    /**
     * 动态规划方法，固定了最后一个元素
     * 对于每一个下标 i ，在 dp 数组里反应的都是截止到 i ，可达到的最长长度
     */
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            // 默认状态，i 位置最长长度起始状态为 1
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                // 如果后面的小于了 当前的 ，那么就更新一下状态，看看可以达到最大多少
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 对整个序列求一个最大值
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2};
//    cout << s.lengthOfLIS(nums);
    nums = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(s.lengthOfLIS(nums) == 4);
    nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    assert(s.lengthOfLIS(nums) == 6);
}