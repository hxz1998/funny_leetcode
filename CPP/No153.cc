/**
 * Created by Xiaozhong on 2020/8/15.
 * Copyright (c) 2020/8/15 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
//        int ans = INT32_MAX;
//        for (int i : nums) ans = min(ans, i); // 很 low 的做法
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];  // 因为数组是升序，所以直接取到左边最小值就可以了
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    Solution s;
    cout << s.findMin(nums) << endl;
}