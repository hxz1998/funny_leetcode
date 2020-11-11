/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        vector<int> dp(nums.size());
        for (int i = 1; i < nums.size(); ++i) {
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums) << endl;
}

class Solution_Old_Version {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int size = nums.size();
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp[size - 1];
    }
};