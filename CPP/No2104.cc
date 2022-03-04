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
    long long subArrayRanges(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
        stack<int> minStack, maxStack;
        for (int idx = 0; idx < n; ++idx) {
            while (!minStack.empty() && nums[minStack.top()] > nums[idx]) minStack.pop();
            minLeft[idx] = minStack.empty() ? -1 : minStack.top();
            minStack.push(idx);

            // 等于号是为了保证严格意义上的小于
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[idx]) maxStack.pop();
            maxLeft[idx] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(idx);
        }

        minStack = stack<int>();
        maxStack = stack<int>();

        for (int idx = n - 1; idx >= 0; --idx) {
            // 等于号是为了保证严格意义上的大于
            while (!minStack.empty() && nums[minStack.top()] >= nums[idx]) minStack.pop();
            minRight[idx] = minStack.empty() ? n : minStack.top();
            minStack.push(idx);

            while (!maxStack.empty() && nums[maxStack.top()] < nums[idx]) maxStack.pop();
            maxRight[idx] = maxStack.empty() ? n : maxStack.top();
            maxStack.push(idx);
        }
        long long sumMax = 0, sumMin = 0;
        for (int idx = 0; idx < n; ++idx) {
            // 以 nums[idx] 为最小值所能构成的数组个数 * nums[idx]
            sumMax += static_cast<long long>(maxRight[idx] - idx) * (idx - maxLeft[idx]) * nums[idx];
            // 以 nums[idx] 为最大值所能构成的数组个数 * nums[idx]
            sumMin += static_cast<long long>(minRight[idx] - idx) * (idx - minLeft[idx]) * nums[idx];
        }
        return sumMax - sumMin;
    }
};