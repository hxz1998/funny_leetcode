/**
 * Created by Xiaozhong on 2020/8/13.
 * Copyright (c) 2020/8/13 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        set<long> num_set;
        long sum_set = 0, sum_array = 0;
        for (int i : nums) {
            sum_array += i;
            num_set.insert(i);
        }
        for (long l : num_set) sum_set += l;
        // 3 * (a + b + c) - 3 * a - 3 * b = 2 * c
        return (int) ((3 * sum_set - sum_array) / 2);
    }
};
