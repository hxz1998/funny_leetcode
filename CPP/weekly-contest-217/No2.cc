/**
 * Created by Xiaozhong on 2020/11/29.
 * Copyright (c) 2020/11/29 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        stack<int> stk;
        stk.push(-1);
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            // 当前元素比栈顶元素小，那么就把栈顶元素移出去
            // 这里仍然需要判断数组剩余长度是否够填满栈
            while (nums[i] < stk.top() && k - stk.size() + 1 < len - i) stk.pop();
            if (stk.size() < k + 1) stk.push(nums[i]);
        }
        vector<int> ret(k);
        while (k > 0) {
            ret[--k] = stk.top();
            stk.pop();
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,4,3,3,5,4,9,6};
    vector<int> ans = s.mostCompetitive(nums, 4);
    return 0;
}