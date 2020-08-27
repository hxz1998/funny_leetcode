/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        int temp[n + 2];
        temp[0] = 1, temp[n + 1] = 1;
        for (int i = 0; i < n; i++) temp[i + 1] = nums[i];
        // len 表示开区间长度，不能小于 3 ，也不能大于 n + 2
        for (int len = 3; len <= n + 2; len++) {
            // left 表示开区间的左端点，右端点为 left + len - 1
            for (int left = 0; left <= n + 2 - len; left++) {
                // index 为开区间索引，从 下标为 1 开始，因为 0 不可以戳破，只是为了帮助计算一直到区间的右边
                for (int index = left + 1; index < left + len - 1; index++) {
                    // 总和 = 左边开区间 (left, index) + (index + left + n - 1) + 最后戳破 k (此时需要用到两个边界 left 与 left + len - 1)
                    int sum = dp[left][index] + dp[index][left + len - 1] +
                              temp[index] * temp[left] * temp[left + len - 1];
                    // 区间 (left, left + n - 1) 求一个最大值
                    dp[left][left + len - 1] = max(sum, dp[left][left + len - 1]);
                }
            }
        }
        // 返回从 0 到 n + 1 的最大值
        return dp[0][n + 1];
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 5, 8};
    cout << s.maxCoins(nums);
}
