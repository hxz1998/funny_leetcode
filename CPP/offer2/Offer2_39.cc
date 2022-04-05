/**
 * Created by Xiaozhong on 2022/3/17.
 * Copyright (c) 2022/3/17 Xiaozhong. All rights reserved.
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

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = static_cast<int>(heights.size());
        vector<int> left(n), right(n);
        stack<int> stk;
        for (int idx = 0; idx < n; ++idx) {
            while (!stk.empty() && heights[stk.top()] >= heights[idx]) stk.pop();
            left[idx] = stk.empty() ? -1 : stk.top();
            stk.push(idx);
        }
        stk = stack<int>();
        for (int idx = n - 1; idx >= 0; --idx) {
            while (!stk.empty() && heights[stk.top()] >= heights[idx]) stk.pop();
            right[idx] = stk.empty() ? n - 1 : stk.top();
            stk.push(idx);
        }
        int ans = 0;
        for (int idx = 0; idx < n; ++idx) {
            ans = max((right[idx] - left[idx]) * heights[idx], ans);
        }
        return ans;
    }
};