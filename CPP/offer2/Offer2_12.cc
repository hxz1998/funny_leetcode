/**
 * Created by Xiaozhong on 2022/3/19.
 * Copyright (c) 2022/3/19 Xiaozhong. All rights reserved.
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
    int pivotIndex(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector<int> prev(n + 1);
        for (int idx = 0; idx < n; ++idx) prev[idx + 1] = prev[idx] + nums[idx];
        int sum = prev[n];
        for (int idx = 0; idx < n; ++idx) {
            if (prev[idx] == prev[n] - prev[idx + 1]) return idx;
        }
        return -1;
    }
};