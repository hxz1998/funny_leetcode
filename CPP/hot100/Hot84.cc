/*
 * Created by Xiaozhong on 3/8/2022.
 * Copyright (c) 3/8/2022 Xiaozhong. All rights reserved.
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
    int largestRectangleArea(vector<int> &heights) {
        int n = static_cast<int>(heights.size());
        if (n == 1) return heights[0];
        else if (n == 0) return 0;
        stack<int> stk;
        vector<int> left(n, 0), right(n, 0);
        for (int idx = 0; idx < n; ++idx) {
            while (!stk.empty() && heights[stk.top()] >= heights[idx]) stk.pop();
            left[idx] = stk.empty() ? -1 : stk.top();
            stk.push(idx);
        }
        stk = stack<int>();
        for (int idx = n - 1; idx >= 0; --idx) {
            while (!stk.empty() && heights[stk.top()] >= heights[idx]) stk.pop();
            right[idx] = stk.empty() ? n : stk.top();
            stk.push(idx);
        }
        int ans = 0;
        for (int idx = 0; idx < n; ++idx) {
            ans = max(ans, (right[idx] - left[idx] - 1) * heights[idx]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    nums = {9, 0};
    Solution s;
    cout << s.largestRectangleArea(nums) << endl;
}