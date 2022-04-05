/**
 * Created by Xiaozhong on 2022/4/4.
 * Copyright (c) 2022/4/4 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n1 = static_cast<int>(nums1.size()), n2 = static_cast<int>(nums2.size());
        vector<vector<int>> ans;
        auto cmp = [&](const pair<int, int> lhs, const pair<int, int> &rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int idx = 0; idx < n1; ++idx) {
            pq.push({idx, 0});
        }
        while (k-- > 0 && !pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            ans.push_back({nums1[top.first], nums2[top.second]});
            if (top.second + 1 < n2) pq.push({top.first, top.second + 1});
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2}, nums2 = {3};
    s.kSmallestPairs(nums1, nums2, 3);
}