/**
 * Created by Xiaozhong on 2020/9/8.
 * Copyright (c) 2020/9/8 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    vector<int> _nums;
    vector<int> original;

    vector<int> copyVector(vector<int> &nums) {
        vector<int> target(nums.size());
        for (int i = 0; i < nums.size(); ++i) target[i] = nums[i];
        return target;
    }

public:
    Solution(vector<int> &nums) {
        _nums = copyVector(nums);
        original = copyVector(nums);
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> aux = copyVector(original);
        for (int i = 0; i < _nums.size(); i++) {
            int index = rand() % aux.size();
            _nums[i] = aux[index];
            aux[index] = aux.back();
            aux.pop_back();
        }
        return _nums;
    }
};