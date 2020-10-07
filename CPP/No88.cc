/**
 * Created by Xiaozhong on 2020/7/29.
 * Copyright (c) 2020/7/29 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int p = m + n - 1, p1 = m - 1, p2 = n - 1;
        while (p2 >= 0 && p1 >= 0) nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
        while (p2 >= 0) nums1[p--] = nums2[p2--];
    }
};

// 调皮解法
//class Solution {
//public:
//    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
//        for (int i = 0; i < n; i++) {
//            nums1[i + m] = (nums2[i]);
//        }
//        sort(nums1.begin(), nums1.end());
//    }
//};

int main() {
    Solution s;
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    s.merge(nums1, 1, nums2, 1);
    for (int i : nums1) {
        cout << i << " ";
    }
}