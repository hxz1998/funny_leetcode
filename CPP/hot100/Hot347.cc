/*
 * Created by Xiaozhong on 3/2/2022.
 * Copyright (c) 3/2/2022 Xiaozhong. All rights reserved.
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

class Solution {
private:
    unordered_map<int, int> cnt;
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        auto cmp = [&](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        };
        for (int num: nums) cnt[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto item: cnt) {
            pq.push(mp(item.first, item.second));
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};