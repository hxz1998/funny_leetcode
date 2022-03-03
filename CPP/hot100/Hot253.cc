/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
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
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });

        priority_queue<int, vector<int>, greater<>> pq;
        int ans = 0;
        for (const vector<int> &interval: intervals) {
            if (pq.empty() || pq.top() > interval[0]) pq.push(interval[1]);
            else {
                pq.pop();
                pq.push(interval[1]);
            }
            ans = max(ans, (int) pq.size());
        }
        return ans;
    }
};