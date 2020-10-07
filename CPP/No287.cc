/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        // 哈希映射的方法太耗时
        /*unordered_map<int, int> mapper;
        for (int i = 1; i <= nums.size(); i++) mapper[i] = 0;
        for (int num : nums) mapper[num]++;
        for (int i = 1; i <= mapper.size(); i++) if (mapper[i]> 1) return i;
        return -1;*/
        // 双指针法，非常规操作：时间换空间
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            // 统计小于等于 nums[mid] 的数字
            for (int num : nums) if (num <= mid) count++;
            /**
             * 如果小于等于 nums[mid] 的数字大于了 mid，那就说明重复数字一定在 [left, mid] 中
             * 否则就在 [mid + 1, right] 中
             */
            if (count > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 2, 2, 2};
    cout << s.findDuplicate(nums) << endl;
}