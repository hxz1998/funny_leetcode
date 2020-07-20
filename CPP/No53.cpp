/**
 * Created by Xiaozhong on 2020/7/20.
 * Copyright (c) 2020/7/20 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int pre = 0, ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pre = max(pre + nums[i], nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }
};

int main(int argc, char *args[]) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    for (int i : nums) {
        cout << i << " ";
    }
}