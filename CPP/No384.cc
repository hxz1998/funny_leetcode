/**
 * Created by Xiaozhong on 2020/9/8.
 * Copyright (c) 2020/9/8 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

/*
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

    */
/** Resets the array to its original configuration and return it. *//*

    vector<int> reset() {
        return original;
    }

    */
/** Returns a random shuffling of the array. *//*

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
};*/

class Solution {
private:
    vector<int> origin;

    vector<int> copyVector(const vector<int> &vec) {
        vector<int> ret(vec.size());
        for (int i = 0; i < vec.size(); ++i) ret[i] = vec[i];
        return ret;
    }

public:
    Solution(vector<int> &nums) {
        origin = copyVector(nums);
    }

    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {
        vector<int> aux = copyVector(origin);
        vector<int> ret(aux.size());
        for (int idx = 0; idx < aux.size(); ++idx) {
            int i = rand() % aux.size();
            ret[idx] = aux[i];
            aux[i] = aux.back();
            aux.pop_back();
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
