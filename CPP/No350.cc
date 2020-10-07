/**
 * Created by Xiaozhong on 2020/8/29.
 * Copyright (c) 2020/8/29 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        // 因为要统计长度最小的序列中每一个元素出现的次数，因此需要调整
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
        unordered_map<int, int> mapper;         // 用来对每个元素进行次数统计
        for (int num : nums1) mapper[num]++;
        vector<int> intersection;               // 用来将重复元素记录
        for (int num : nums2) {
            if (mapper.count(num)) {            // 如果 num 出现在 nums1 而且在 nums2 中
                intersection.push_back(num);    // 那么就将该元素加入返回值
                --mapper[num];                  // 同时将它在 num1 中的次数减一
                // 如果已经减到了 0 ，那么接下来不可能再把它加入返回值，因此直接在映射表中去除掉
                if (mapper[num] == 0) mapper.erase(num);
            }
        }
        return intersection;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution s;
    vector<int> ans = s.intersect(nums1, nums2);
    for (int i : ans) cout << i << " ";
}