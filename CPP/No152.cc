/**
 * Created by Xiaozhong on 2020/8/15.
 * Copyright (c) 2020/8/15 Xiaozhong. All rights reserved.
 */

#include "algorithm"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        vector<int> dp_max(nums.size()), dp_min(nums.size());
        int ans = dp_max[0] = dp_min[0] = nums.front();
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                dp_max[i] = max(dp_max[i - 1] * nums[i], nums[i]);
                dp_min[i] = min(dp_min[i - 1] * nums[i], nums[i]);
            } else {
                dp_max[i] = max(dp_min[i - 1] * nums[i], nums[i]);
                dp_min[i] = min(dp_max[i - 1] * nums[i], nums[i]);
            }
            ans = max(dp_max[i], ans);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution s;
    cout << s.maxProduct(nums) << endl;
}