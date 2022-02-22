/**
 * Created by Xiaozhong on 2022/2/22.
 * Copyright (c) 2022/2/22 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    int binarySearch(const vector<int> &nums, int target, bool lower) {
        int left = 0, right = nums.size() - 1, ans = nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int begin = binarySearch(nums, target, true);
        int end = binarySearch(nums, target, false) - 1;
        if (begin <= end && begin >= 0 && end < nums.size() && nums[begin] == target && nums[end] == target) {
            return {begin, end};
        }
        return {-1, -1};
    }
};

ostream &operator<<(ostream &os, const vector<int> &nums) {
    for (int num: nums) os << num << " ";
    return os;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution s;
    cout << s.searchRange(nums, 8) << endl;

    nums = {2, 2};
    cout << s.searchRange(nums, 3) << endl;
}