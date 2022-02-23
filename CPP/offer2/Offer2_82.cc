/**
 * Created by Xiaozhong on 2022/2/22.
 * Copyright (c) 2022/2/22 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
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
            if (idx > start && candidates[idx] == candidates[idx - 1]) continue;
            if (candidates[idx] > target) break;
            buffer.emplace_back(candidates[idx]);
            backtrack(candidates, ans, buffer, target - candidates[idx], idx + 1);
            buffer.pop_back();
        }
    }
};

ostream &operator<<(ostream &os, const vector<vector<int>> &nums) {
    for (const vector<int> &item: nums) {
        for (int num: item) os << num << " ";
        os << endl;
    }
    return os;
}

int main() {
    Solution s;
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5, 1, 1, 1};
    cout << s.combinationSum2(nums, 8) << endl;
}