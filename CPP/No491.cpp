/**
 * Created by Xiaozhong on 2020/10/2.
 * Copyright (c) 2020/10/2 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> buf;
    void dfs(int cur, int last, vector<int> &nums) {
        if (cur == nums.size()) {
            if (buf.size() >= 2) {
                ans.emplace_back(buf);
            }
            return;
        }
        if (nums[cur] >= last) {
            buf.emplace_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            buf.pop_back();
        }
        if (nums[cur] != last) {
            dfs(cur+1, last, nums);
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        dfs(0, INT32_MIN, nums);
        return ans;
    }
};