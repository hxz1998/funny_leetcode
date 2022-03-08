/*
 * Created by Xiaozhong on 3/8/2022.
 * Copyright (c) 3/8/2022 Xiaozhong. All rights reserved.
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
    int trap(vector<int> &height) {
        int n = static_cast<int>(height.size());
        vector<int> left(n), right(n);
        for (int idx = 0; idx < n; ++idx) {
            if (idx == 0) {
                left[idx] = height[idx];
                right[n - idx - 1] = height[n - idx - 1];
            } else {
                left[idx] = max(left[idx - 1], height[idx]);
                right[n - idx - 1] = max(right[n - idx], height[idx]);
            }
        }
        int ans = 0;
        for (int idx = 0; idx < n; ++idx) ans = max(ans, min(right[idx], left[idx]) * height[idx]);
        return ans;
    }
};