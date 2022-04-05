/**
 * Created by Xiaozhong on 2022/3/30.
 * Copyright (c) 2022/3/30 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });
        vector<vector<int>> ans;
        int n = static_cast<int>(intervals.size());
        ans.push_back(intervals[0]);
        for (int idx = 1; idx < n; ++idx) {
            if (ans.back()[1] >= intervals[idx][0]) ans.back()[1] = max(ans.back()[1], intervals[idx][1]);
            else ans.push_back(intervals[idx]);
        }
        return ans;
    }
};