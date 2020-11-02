/**
 * Created by Xiaozhong on 2020/11/2.
 * Copyright (c) 2020/11/2 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int duplicate = -1, missing = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) duplicate = nums[i];
            else if (nums[i] > nums[i - 1] + 1) missing = nums[i - 1] + 1;
        }
        return {duplicate, nums.back() != nums.size() ? (int) nums.size() : missing};
    }

    void operator<<(vector<int> &nums) {
        vector<int> ans = findErrorNums(nums);
        cout << ans.front() << " " << ans.back() << endl;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2, 4};
    solution << nums;
    nums = {1, 1};
    solution << nums;
    nums = {2, 2};
    solution << nums;
    nums = {3, 2, 3, 4, 6, 5};
    solution << nums;
}