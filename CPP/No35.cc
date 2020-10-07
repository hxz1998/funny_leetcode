//
// Created by cherry on 2020/7/13.
//
#include <iostream>
#include <vector>

using namespace std;

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,6], 2
输出: 1

示例 3:
输入: [1,3,5,6], 7
输出: 4

示例 4:
输入: [1,3,5,6], 0
输出: 0
*/

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return length;
    }
};

int main(int argc, char *args[]) {
    vector<int> nums = {1, 3, 5, 6};
    Solution s;
    cout << s.searchInsert(nums, 5) << endl;
    cout << s.searchInsert(nums, 2) << endl;
    cout << s.searchInsert(nums, 7) << endl;
    cout << s.searchInsert(nums, 0) << endl;
}

