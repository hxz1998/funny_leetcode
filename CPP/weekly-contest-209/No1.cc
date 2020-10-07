/**
 * Created by Xiaozhong on 2020/10/4.
 * Copyright (c) 2020/10/4 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int specialArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int minimum = nums.front(), maximum = nums.back();
        for (int i = 0; i <= maximum; ++i) {
            auto iter = lower_bound(nums.begin(), nums.end(), i);
            if (i == nums.end() - iter) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 3, 4, 4};
    cout << s.specialArray(nums) << endl;
    nums = {0, 0};
    cout << s.specialArray(nums) << endl;
    nums = {3, 5};
    cout << s.specialArray(nums) << endl;
}
