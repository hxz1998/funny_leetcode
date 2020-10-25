/**
 * Created by Xiaozhong on 2020/10/25.
 * Copyright (c) 2020/10/25 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int> nums, int begin, int end) {
        if (end - begin == 1) return true;
        sort(nums.begin() + begin, nums.begin() + end + 1);
        int step = nums[begin + 1] - nums[begin];
        for (int i = begin + 2; i <= end; ++i) {
            if (nums[i] - nums[i - 1] != step) return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); ++i) {
            ans.emplace_back(check(nums, l[i], r[i]));
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 6, 5, 9, 3, 7};
    vector<int> l = {0, 0, 2}, r = {2, 3, 5};
    vector<bool> ans = s.checkArithmeticSubarrays(nums, l, r);
    for (bool b : ans) {
        cout << b << " ";
    }
    cout << endl;
    nums = {-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
    l = {0, 1, 6, 4, 8, 7}, r = {4, 4, 9, 7, 9, 10};
    ans = s.checkArithmeticSubarrays(nums, l, r);
    for (bool b : ans) {
        cout << b << " ";
    }
    cout << endl;

}