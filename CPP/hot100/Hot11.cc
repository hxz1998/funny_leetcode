/**
 * Created by Xiaozhong on 2022/2/8.
 * Copyright (c) 2022/2/8 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                ans = max(ans, (right - left) * height[left]);
                ++left;
            } else {
                ans = max((right - left) * height[right], ans);
                --right;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(nums) << endl;
}