/**
 * Created by Xiaozhong on 2020/7/29.
 * Copyright (c) 2020/7/29 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

int main(int argc, char **args) {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution s;
    int ans = s.largestRectangleArea(heights);
    cout << ans << endl;
}

