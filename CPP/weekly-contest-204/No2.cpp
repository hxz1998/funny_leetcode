/**
 * Created by Xiaozhong on 2020/8/30.
 * Copyright (c) 2020/8/30 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

/**
 * 输入：nums = [1,-2,-3,4]
 * 输出：4
 * 解释：数组本身乘积就是正数，值为 24 。
 */
class Solution {
public:
    int getMaxLen(vector<int> &nums) {
        /**
         * dp[i][0] : 以 nums[i] 结尾，乘积为 正 的最长子数组长度
         * dp[i][1] : 以 nums[i] 结尾，乘积为 负 的最长子数组长度
         */
        int dp[nums.size() + 1][2];
        dp[0][0] = dp[0][1] = 0;
        int ans = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (nums[i - 1] == 0) {
                // 当 nums[i] == 0 时，两者均无法达到要求，所以为 0
                dp[i][0] = dp[i][1] = 0;
            } else if (nums[i - 1] > 0) {
                // 当 nums[i] > 0 时，正数只需要自己 + 1
                dp[i][0] = dp[i - 1][0] + 1;
                // 负数要看前面是否为 0 ，如果为 0， 那么自己一个 正数 是无法构成乘积为 负 的序列的，所以直接给 0
                dp[i][1] = dp[i - 1][1] ? dp[i - 1][1] + 1 : 0;
            } else {
                // 理由同上
                dp[i][0] = dp[i - 1][1] ? dp[i - 1][1] + 1 : 0;
                dp[i][1] = dp[i - 1][0] + 1;
            }
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, -2, -3, 4};
    Solution s;
    cout << s.getMaxLen(nums) << endl;
    nums = {0, 1, -2, -3, -4};
    cout << s.getMaxLen(nums) << endl;
    nums = {-1, -2, -3, 0, 1};
    cout << s.getMaxLen(nums) << endl;
}