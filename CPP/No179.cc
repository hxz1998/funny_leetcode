/**
 * Created by Xiaozhong on 2020/8/18.
 * Copyright (c) 2020/8/18 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
    static bool compare(const int &a, const int &b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) return "0";
        string ans = "";
        for (auto &x : nums) ans += to_string(x);
        return ans;
    }
};