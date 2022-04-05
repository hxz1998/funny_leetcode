/**
 * Created by Xiaozhong on 2022/4/3.
 * Copyright (c) 2022/4/3 Xiaozhong. All rights reserved.
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
    void
    backtrack(const vector<int> &candidates, vector<vector<int>> &ans, vector<int> &buffer,
              int target, int start) {
        if (target == 0) {
            ans.push_back(buffer);
            return;
        }
        if (target < 0) return;
        for (int idx = start; idx < static_cast<int>(candidates.size()); ++idx) {
            buffer.push_back(candidates[idx]);
            backtrack(candidates, ans, buffer, target - candidates[idx], idx);
            buffer.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> buffer;
        vector<vector<int>> ans;
        backtrack(candidates, ans, buffer, target, 0);
        return ans;
    }
};