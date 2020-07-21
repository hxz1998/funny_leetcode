/**
 * Created by Xiaozhong on 2020/7/21.
 * Copyright (c) 2020/7/21 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int max_position = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_position) return false;
            max_position = max(max_position, i + nums[i]);
        }
        return true;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution s;
    cout << s.canJump(nums) << endl;
}