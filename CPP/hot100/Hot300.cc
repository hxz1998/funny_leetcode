/*
 * Created by Xiaozhong on 3/2/2022.
 * Copyright (c) 3/2/2022 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

/*
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        size_t n = nums.size();
        vector<int> dp(n, 1);
        for (size_t curr = 0; curr < n; ++curr) {
            int mx = 0;
            for (size_t prev = 0; prev < curr; ++prev) {
                if (nums[prev] < nums[curr]) mx = max(mx, dp[prev]);
            }
            dp[curr] += mx;
        }
        return *max_element(dp.begin(), dp.end());
    }
};*/

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        size_t n = nums.size();
        vector<int> d(n + 1, 0);
        d[1] = nums[0];
        int len = 1;
        for (size_t idx = 1; idx < n; ++idx) {
            if (nums[idx] > d[len]) d[++len] = nums[idx];
            else {
                size_t left = 1, right = len, pos = 0;
                while (left < right) {
                    size_t mid = left + ((right - left) >> 1);
                    if (d[mid] < nums[idx]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                d[pos + 1] = nums[idx];
            }
        }
        return len;
    }
};
