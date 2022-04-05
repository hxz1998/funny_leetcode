/**
 * Created by Xiaozhong on 2022/3/15.
 * Copyright (c) 2022/3/15 Xiaozhong. All rights reserved.
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
private:
    int ans = 0;

    void helper(const vector<int> &nums, int buffer, int target, int len) {
        if (buffer == target) ans++;
        if (len == nums.size()) return;
        helper(nums, buffer | nums[len], target, len + 1);
        helper(nums, buffer, target, len + 1);
    }

public:
    int countMaxOrSubsets(vector<int> &nums) {
        int xorResult = 0;
        int n = static_cast<int>(nums.size());
        for (const int &num: nums) xorResult |= num;
        helper(nums, 0, xorResult, 0);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 4, 5, 5, 6, 6, 7, 8};
    cout << s.countMaxOrSubsets(nums) << endl;
}