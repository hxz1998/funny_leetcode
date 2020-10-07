/**
 * Created by Xiaozhong on 2020/8/19.
 * Copyright (c) 2020/8/19 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k % nums.size());
        reverse(nums.begin() + k % nums.size(), nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(nums, 3);
    for (int i : nums) {
        cout << i << " ";
    }
}