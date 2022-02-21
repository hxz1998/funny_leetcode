/**
 * Created by Xiaozhong on 2022/2/6.
 * Copyright (c) 2022/2/6 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        unordered_map<int, int> mapper;
        for (int num: nums) mapper[num]++;
        int ans = 0;
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            if (iter->second == 1) ans += iter->first;
        }
        return ans;
    }
};