/**
 * Created by Xiaozhong on 2020/10/14.
 * Copyright (c) 2020/10/14 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums);
};

inline int Solution::singleNonDuplicate(vector<int> &nums) {
    if (nums.empty()) return 0;
    int ans = nums.front();
    for (int i = 1; i < nums.size(); ++i) ans ^= nums[i];
    return ans;
}

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << s.singleNonDuplicate(nums) << endl;
}