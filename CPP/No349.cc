/**
 * Created by Xiaozhong on 2020/8/29.
 * Copyright (c) 2020/8/29 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "unordered_set"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set;
        unordered_set<int> ans;
        for (int i : nums1) set.insert(i);
        for (int i : nums2) if (set.count(i)) ans.insert(i);
        return vector<int>(ans.begin(), ans.end());
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    vector<int> ans = s.intersection(nums1, nums2);
    for (int i : ans) cout << i << " ";
}