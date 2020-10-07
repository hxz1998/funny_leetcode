/**
 * Created by Xiaozhong on 2020/7/24.
 * Copyright (c) 2020/7/24 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> buffer;
        backtrack(0, nums, buffer);
        return ans;
    }

private:
    vector<vector<int>> ans;

    void backtrack(int first, vector<int> &nums, vector<int> &buffer) {
        ans.push_back(buffer);
        for (int i = first; i < nums.size(); i++) {
            buffer.push_back(nums[i]);
            backtrack(i + 1, nums, buffer);
            buffer.pop_back();
        }
    }
};

int main() {

}