/*
 * Created by Xiaozhong on 3/4/2022.
 * Copyright (c) 3/4/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> ans;
        for (int num: nums)
            nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] > 0) ans.push_back(idx + 1);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution s;
    for (int num: s.findDisappearedNumbers(nums)) cout << num << " ";
}