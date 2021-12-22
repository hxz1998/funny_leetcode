/**
 * Created by Xiaozhong on 2021/12/18.
 * Copyright (c) 2021/12/18 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        int n = 0, m = 1;
        for (int num: nums) n ^= num;
        while ((n & m) == 0) m <<= 1;
        int x = 0, y = 0;
        for (int num: nums) {
            if ((num & m) == 0) x ^= num;
            else y ^= num;
        }
        return {x, y};
    }
};