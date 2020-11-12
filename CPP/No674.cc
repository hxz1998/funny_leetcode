/**
 * Created by Xiaozhong on 2020/11/12.
 * Copyright (c) 2020/11/12 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            else continue;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dp[i]);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << s.findLengthOfLCIS(nums) << endl;
}
