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
private:
    void backtrack(const vector<int> &nums, int start,
                   vector<int> &buffer, vector<vector<int>> &ans) {
        if (start == static_cast<int>(nums.size())) {
            ans.push_back(buffer);
            return;
        }
        backtrack(nums, start + 1, buffer, ans);
        buffer.push_back(nums[start]);
        backtrack(nums, start + 1, buffer, ans);
        buffer.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> buffer;
        vector<vector<int>> ans;
        backtrack(nums, 0, buffer, ans);
        return ans;
    }
};