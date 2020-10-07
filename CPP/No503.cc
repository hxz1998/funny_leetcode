/**
 * Created by Xiaozhong on 2020/10/5.
 * Copyright (c) 2020/10/5 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> ans(nums.size());
        stack<int> stk;
        for (int i = 2 * nums.size() - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i % nums.size()]) stk.pop();
            ans[i % nums.size()] = stk.empty() ? -1 : nums[stk.top()];
            stk.push(i % nums.size());
        }
        return ans;
    }
};