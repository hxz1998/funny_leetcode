/**
 * Created by Xiaozhong on 2020/10/29.
 * Copyright (c) 2020/10/29 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    ans += right - left;
                    --right;
                }
                else ++left;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 3, 4};
    cout << s.triangleNumber(nums) << endl;
}