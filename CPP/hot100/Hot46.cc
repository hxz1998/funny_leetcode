/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/*class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> buffer;
        backtrack(nums, ans, buffer, 0);
        return ans;
    }

private:
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int> &buffer, int start) {
        if (start == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int idx = start; idx < nums.size(); ++idx) {
            swap(nums[idx], nums[start]);
            backtrack(nums, ans, buffer, start + 1);
            swap(nums[idx], nums[start]);
        }
    }
};*/
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> buffer;
        vector<bool> visited(nums.size(), false);
        backtrack(ans, nums, buffer, visited);
        return ans;
    }

private:
    void backtrack(vector<vector<int>> &ans, const vector<int> &nums, vector<int> &buffer, vector<bool> &visited) {
        if (buffer.size() == nums.size()) {
            ans.emplace_back(buffer);
            return;
        }
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (visited[idx]) continue;
            buffer.emplace_back(nums[idx]);
            visited[idx] = true;
            backtrack(ans, nums, buffer, visited);
            visited[idx] = false;
            buffer.pop_back();
        }
    }
};

ostream &operator<<(ostream &os, const vector<vector<int>> &data) {
    for (const vector<int> &item: data) {
        for (int num: item) os << num << ", ";
        os << endl << flush;
    }
    return os;
}

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    cout << s.permute(nums) << endl;
}

