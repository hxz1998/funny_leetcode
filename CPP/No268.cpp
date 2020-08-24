/**
 * Created by Xiaozhong on 2020/8/24.
 * Copyright (c) 2020/8/24 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) ans += (i - nums[i]);
        return ans + nums.size();
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 0, 1};
    cout << s.missingNumber(nums);
}
