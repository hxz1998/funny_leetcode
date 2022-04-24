/**
 * Created by Xiaozhong on 2022/4/19.
 * Copyright (c) 2022/4/19 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
private:
    int helper(const vector<int> &nums, int left, int right) {
        vector<int> dp(right - left + 1);
        dp[0] = nums[left];
        dp[1] = max(nums[left + 1], dp[0]);
        for (int idx = 2; idx < (right - left + 1); ++idx) {
            dp[idx] = max(dp[idx - 1], dp[idx - 2] + nums[idx + left]);
        }
        return dp[right];
    }

public:
    int rob(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 6};
    cout << s.rob(nums) << endl;
}