/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    void dfs(int curr, vector<vector<int>> &ans, const vector<int> &nums, vector<int> &buffer) {
        if (curr == nums.size()) {
            ans.emplace_back(buffer);
            return;
        }
        buffer.emplace_back(nums[curr]);
        dfs(curr + 1, ans, nums, buffer);
        buffer.pop_back();
        dfs(curr + 1, ans, nums, buffer);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>());
        vector<int> buffer;
        dfs(0, ans, nums, buffer);
        return ans;
    }
};