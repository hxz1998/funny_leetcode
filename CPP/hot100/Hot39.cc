/**
 * Created by Xiaozhong on 2022/2/22.
 * Copyright (c) 2022/2/22 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> buffer;
        backtrack(candidates, ans, buffer, target, 0);
        return ans;
    }

private:
    void
    backtrack(const vector<int> &candidates, vector<vector<int>> &ans, vector<int> &buffer, int target, int start) {
        if (target == 0) {
            ans.emplace_back(buffer);
            return;
        }
        for (int idx = start; idx < candidates.size(); ++idx) {
            if (candidates[idx] > target) break;
            buffer.emplace_back(candidates[idx]);
            backtrack(candidates, ans, buffer, target - candidates[idx], idx);
            buffer.pop_back();
        }
    }
};