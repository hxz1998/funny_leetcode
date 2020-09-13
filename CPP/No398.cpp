/**
 * Created by Xiaozhong on 2020/9/13.
 * Copyright (c) 2020/9/13 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

/*class Solution {
private:
    unordered_map<int, vector<int>> mapper;
public:
    Solution(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i)
            mapper[nums[i]].push_back(i);
    }

    int pick(int target) {
        return mapper[target][rand() % mapper[target].size()];
    }
};*/

class Solution {
private:
    vector<int> _nums;
public:
    Solution(vector<int> &nums) : _nums(nums) {
    }

    int pick(int target) {
        int index = 0, n = 0;
        for (int i = 0; i < _nums.size(); ++i) {
            if (_nums[i] == target) {
                ++n;
                if (rand() % n == 0) index = i;
            }
        }
        return index;
    }
};

