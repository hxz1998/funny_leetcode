/**
 * Created by Xiaozhong on 2020/9/26.
 * Copyright (c) 2020/9/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        if (nums.size() < 3) return false;
        stack<int> st;
        vector<int> minimal(nums.size());
        minimal[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) minimal[i] = min(nums[i], minimal[i - 1]);

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] > minimal[i]) {
                while (!st.empty() && st.top() <= minimal[i]) st.pop();
                if (!st.empty() && st.top() < nums[i]) return true;
                st.push(nums[i]);
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.find132pattern(nums) << endl;
    nums = {3, 1, 4, 2};
    cout << s.find132pattern(nums) << endl;
    nums = {1, -4, 2, -1, 3, -3, -4, 0, -3, -1};
    cout << s.find132pattern(nums) << endl;
}