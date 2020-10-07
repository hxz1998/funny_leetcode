/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3) return false;  // 特例判断
        int small = INT32_MAX, mid = INT32_MAX; // small用来指示序列中的最小值，mid用来指示序列中的中间值
        for (auto &i : nums) {
            // 扫描并更新
            if (i <= small) small = i;      // 一定要添加 <= ，因为需要及时更新 small 和 mid 的位置
            else if (i <= mid) mid = i;
            else if (i > mid) return true;
        }
        return false;
    }
};