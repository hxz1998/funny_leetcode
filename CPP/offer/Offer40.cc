/*
 * Created by Xiaozhong on 12/13/2021.
 * Copyright (c) 12/13/2021 Xiaozhong. All rights reserved.
 */
#include <queue>
#include "vector"
#include "iostream"
#include "deque"

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        if (k == arr.size()) return arr;
        priority_queue<int, vector<int>, less<>> pq;
        for (int num: arr) {
            if (pq.size() < k) pq.push(num);
            else {
                pq.push(num);
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.emplace_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};