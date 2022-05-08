/**
 * Created by Xiaozhong on 2020/11/22.
 * Copyright (c) 2020/11/22 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
//        if (k <= 1) return 0;
//        int product = 1, ans = 0, left = 0, right = 0;
//        for (; right < nums.size(); ++right) {
//            product *= nums[right];
//            while (product >= k) product /= nums[left++];
//            ans += (right - left + 1);
//        }
//        return ans;
//    }
//};

namespace ez {
    int accumulate(int left, int right) {
        return (1 + right + 1) * (right - left + 1) / 2;
    }
}

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = static_cast<int>(nums.size());
        int ans = 0;
        int left = 0, right = 0, product = 1;
        while (right < n) {
            product *= nums[right];
            while (product >= k) product /= nums[left++];
            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {10, 5, 2, 6};
    Solution s;
    cout << s.numSubarrayProductLessThanK(nums, 100) << endl;
}