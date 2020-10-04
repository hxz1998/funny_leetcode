/**
 * Created by Xiaozhong on 2020/10/3.
 * Copyright (c) 2020/10/3 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ans(nums1.size());
        stack<int> stk;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!stk.empty() && nums2[i] > stk.top()) {
                umap[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        while (!stk.empty()) {
            umap[stk.top()] = -1;
            stk.pop();
        }
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = umap[nums1[i]];
        }
        return ans;
    }
};