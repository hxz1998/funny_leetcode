/*
 * Created by Xiaozhong on 3/10/2022.
 * Copyright (c) 3/10/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

/*class Solution {
    struct cmp {
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = static_cast<int>(nums.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int idx = 0; idx < k; ++idx) {
            pq.push(mp(nums[idx], idx));
        }
        vector<int> ans(n - k + 1);
        ans[0] = pq.top().first;
        for (int idx = k; idx < n; ++idx) {
            pq.push(mp(nums[idx], idx));
            while (!pq.empty() && pq.top().second <= idx - k) pq.pop();
            ans[idx - k + 1] = pq.top().first;
        }
        return ans;
    }
};*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = static_cast<int>(nums.size());
        deque<int> q;
        for (int idx = 0; idx < k; ++idx) {
            while (!q.empty() && nums[idx] >= nums[q.back()]) q.pop_back();
            q.push_back(idx);
        }

        vector<int> ans{nums[q.front()]};
        for (int idx = k; idx < n; ++idx) {
            while (!q.empty() && nums[idx] >= nums[q.back()]) q.pop_back();
            while (!q.empty() && idx - q.front() >= k) q.pop_front();
            q.push_back(idx);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;
    s.maxSlidingWindow(nums, 3);
}