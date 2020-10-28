/**
 * Created by Xiaozhong on 2020/10/28.
 * Copyright (c) 2020/10/28 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        return max(nums[0] * nums[1] * nums[length - 1], nums[length - 1] * nums[length - 2] * nums[length - 3]);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.maximumProduct(nums) << endl;
    nums = {-100, -98, -1, 2, 3, 4};
    cout << s.maximumProduct(nums) << endl;
}