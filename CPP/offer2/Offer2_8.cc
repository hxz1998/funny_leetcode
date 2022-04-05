/**
 * Created by Xiaozhong on 2022/3/21.
 * Copyright (c) 2022/3/21 Xiaozhong. All rights reserved.
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
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector<int> prev(n + 1);
        for (int idx = 1; idx <= n; ++idx) {
            prev[idx] = prev[idx - 1] + nums[idx - 1];
        }
        if (prev[n] < target) return 0;
        int left = 0, right = 0;
        int ans = n;
        while (right <= n) {
            while (right <= n && prev[right] - prev[left] < target) right++;
            if (n < right) {
                while (left <= n && prev[n] - prev[left] >= target) left++;
            } else {
                while (left < right && prev[right] - prev[left] >= target) left++;
            }
            ans = min(ans, right - left + 1);
        }
        return ans;
    }
};