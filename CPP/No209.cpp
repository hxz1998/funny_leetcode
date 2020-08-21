/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    // 双指针法
    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        if (!n) return 0;
        // 分别定义子序列起始 start 指针、终止 end 指针，以及总和 sum
        int ans = INT32_MAX, start = 0, end = 0, sum = 0;
        while (end < n) {
            // 终止指针负责读入
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start++];       // 起始指针负责吐出
            }
            end++;
        }
        return ans == INT32_MAX ? 0 : ans;  //检查是否找到了合法的子序列长度
    }
};