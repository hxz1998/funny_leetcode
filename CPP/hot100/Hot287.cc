/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
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
    int findDuplicate(vector<int> &nums) {
        int n = (int) nums.size();
        int left = 0, right = n, ans = 0;
        while (left < right) {
            // 目标大小
            int mid = (left + right) >> 1;
            int cnt = 0;
            // 看看有多少小于等于 目标数 的
            for (int num: nums) cnt += num <= mid;
            // 如果小于目标数的数字个数小于等于目标数本身，说明最终结果在右边出现
            if (cnt <= mid) left = mid + 1;
            else {
                ans = mid;
                right = mid;
            }
        }
        return ans;
    }
};