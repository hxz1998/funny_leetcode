/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "algorithm"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        if (nums.size() == 0) return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.containsDuplicate(nums) << endl;
}