/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.size() == 1 || k == 1) return nums;
        vector<int> ans(nums.size() - k + 1);
        ans[0] = INT32_MIN;
        for (int i = 0; i < k; i++) ans[0] = max(ans[0], nums[i]);
        for (int i = 1; i <= nums.size() - k; i++) {
            ans[i] = max(ans[i - 1], nums[i + k - 1]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;
    vector<int> ans = s.maxSlidingWindow(nums, 3);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> nums2 = {7, 2, 4};
    vector<int> ans2 = s.maxSlidingWindow(nums2, 2);
    for (int i : ans2) {
        cout << i << " ";
    }
}