//
// Created by cherry on 2020/7/13.
//
#include <iostream>
#include <vector>

/**
 *
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

 */

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans = {-1, -1};
        int leftIdx = findBoundary(nums, target, true);
        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return ans;
        }

        ans[0] = leftIdx;
        ans[1] = findBoundary(nums, target, false) - 1;
        return ans;
    }

    int findBoundary(vector<int> &nums, int target, bool left) {
        int l = 0, h = nums.size();
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] > target || (left && nums[mid] == target)) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(int argc, char *args[]) {
    Solution s;
    vector<int> v = vector<int>{5, 7, 7, 8, 8, 10};
    for (int i : s.searchRange(v, 8)) {
        cout << i << "- ";
    }
}

