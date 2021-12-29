/**
 * Created by Xiaozhong on 2021/12/21.
 * Copyright (c) 2021/12/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        vector<int> cnt(31, 0);
        for (int num: nums) {
            for (int i = 0; i < 31; ++i) {
                cnt[i] += (num & (1 << i)) == 0 ? 0 : 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            ans |= (cnt[i] % 3) << i;
        }
        return ans;
    }
};