/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        // l 用来记录 index 左侧的乘积， r 用来记录 index 右侧的乘积
        vector<int> l(nums.size()), r(nums.size()), ans(nums.size());;
        l[0] = 1, r[nums.size() - 1] = 1;   // index = 0 时，左侧无值可乘，因此为 1，同理，index = len - 1 时，也为 1
        for (int i = 1; i < nums.size(); i++) l[i] = l[i - 1] * nums[i - 1];
        for (int i = nums.size() - 2; i >= 0; i--) r[i] = r[i + 1] * nums[i + 1];
        // ans[i] = i 左侧的乘积 * i 右侧的乘积
        for (int i = 0; i < nums.size(); i++) ans[i] = l[i] * r[i];
        return ans;
    }
};
