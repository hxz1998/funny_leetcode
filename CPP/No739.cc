/**
 * Created by Xiaozhong on 2020/12/1.
 * Copyright (c) 2020/12/1 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        int n = T.size();
        stack<int> stk;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                int prevIdx = stk.top();
                ans[prevIdx] = i - prevIdx;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};