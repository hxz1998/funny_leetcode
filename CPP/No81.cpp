/**
 * Created by Xiaozhong on 2020/7/28.
 * Copyright (c) 2020/7/28 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 1, 1, 1};
    cout << s.search(nums, 3) << endl;
}
