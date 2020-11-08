/**
 * Created by Xiaozhong on 2020/11/8.
 * Copyright (c) 2020/11/8 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        if (nums.size() == 1) return true;
        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                count++;
                if (count > 1) return false;
                if (i - 2 >= 0 && nums[i] < nums[i - 2]) nums[i] = nums[i - 1];
                else nums[i - 1] = nums[i];
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 4, 2, 3};
    cout << s.checkPossibility(nums);
}