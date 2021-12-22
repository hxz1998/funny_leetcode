<<<<<<< HEAD
/**
 * Created by Xiaozhong on 2021/12/21.
 * Copyright (c) 2021/12/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        int cnt = 0, mx = INT32_MIN, ms = INT32_MAX;
        unordered_set<int> st;
        for (int num: nums) {
            if (num == 0) cnt++;
            else {
                mx = max(mx, num);
                ms = min(ms, num);
                if (st.find(num) != st.end()) return false;
                st.insert(num);
            }
        }
        return mx - ms < 5;
    }
};