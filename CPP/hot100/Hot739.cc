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
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<pair<int, int>> stk;
        size_t n = temperatures.size();
        vector<int> ans(n, 0);
        stk.push(mp(temperatures[n - 1], n - 1));
        for (int idx = n - 2; idx >= 0; --idx) {
            while (!stk.empty() && stk.top().first <= temperatures[idx]) stk.pop();
            ans[idx] = stk.empty() ? 0 : stk.top().second - (int) idx;
            stk.push(mp(temperatures[idx], idx));
        }
        return ans;
    }
};