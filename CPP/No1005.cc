/*
 * Created by Xiaozhong on 12/3/2021.
 * Copyright (c) 12/3/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        while (idx < nums.size()) {
            if (nums[idx] >= 0) break;
        }
        if (k <= idx) {
            int ans = 0;
            for (int i = 0; i < k; ++i) ans += -nums[i];
            for (int i = k; i < nums.size(); ++i) ans += nums[i];
            return ans;
        } else {
            k -= idx;
            int ans = 0;
            for (int i = 0; i < idx; ++i) nums[i] = -nums[i];
            sort(nums.begin(), nums.end());
            if (k % 2 == 0) {
                for (int num : nums) ans += num;
            } else {
                for (int i = 0; i < nums.size(); ++i) {
                    if (i == 0) ans += -nums[i];
                    else ans += nums[i];
                }
            }
            return ans;
        }
    }
};

int main() {

}