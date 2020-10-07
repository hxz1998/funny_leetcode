/**
 * Created by Xiaozhong on 2020/8/26.
 * Copyright (c) 2020/8/26 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        sum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) sum[i + 1] += (sum[i] + nums[i]);
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

