/**
 * Created by Xiaozhong on 2020/7/30.
 * Copyright (c) 2020/7/30 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> buffer;

    void dfs(int start, vector<int> &nums) {
        ans.push_back(buffer);
        if (start == nums.size()) return;
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            buffer.push_back(nums[i]);
            dfs(i + 1, nums);
            buffer.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    Solution s;
    vector<vector<int>> ans = s.subsetsWithDup(nums);
    for (vector<int> item : ans) {
        for (int i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}