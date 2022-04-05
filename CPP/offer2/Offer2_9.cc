/**
 * Created by Xiaozhong on 2022/3/22.
 * Copyright (c) 2022/3/22 Xiaozhong. All rights reserved.
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
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = static_cast<int>(nums.size());
        int product = 1, left = 0, ans = 0;
        for (int right = 0; right < n; ++right) {
            product *= nums[right];
            while (product > k) product /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
};