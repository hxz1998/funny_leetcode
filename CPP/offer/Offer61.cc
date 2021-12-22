/**
 * Created by Xiaozhong on 2021/12/21.
 * Copyright (c) 2021/12/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        int cnt = 0, mx = -1, ms = INT32_MAX;
        for (int num: nums) {
            if (num == 0) cnt++;
            else {
                mx = max(mx, num);
                ms = min(ms, num);
            }
        }
        if (mx - ms > 5) return false;

    }
};