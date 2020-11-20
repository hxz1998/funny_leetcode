/**
 * Created by Xiaozhong on 2020/11/19.
 * Copyright (c) 2020/11/19 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, int> left, right, count;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (left.count(x) == 0) left[x] = i;
            right[x] = i;
            ++count[x];
        }

        int ans = nums.size(), degree = 0;
        for (auto iter : count) degree = max(degree, iter.second);
        for (auto iter : count) {
            if (iter.second == degree)
                ans = min(ans, right[iter.first] - left[iter.first] + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
    cout << s.findShortestSubArray(nums) << endl;
    nums = {1, 2, 2, 3, 1};
    cout << s.findShortestSubArray(nums) << endl;
    nums = {1, 3, 2, 2, 3, 1};
    cout << s.findShortestSubArray(nums) << endl;
}