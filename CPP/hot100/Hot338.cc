/*
 * Created by Xiaozhong on 3/4/2022.
 * Copyright (c) 3/4/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        int highBit = 0;
        for (int idx = 1; idx <= n; ++idx) {
            if (idx & (idx - 1)) {
                highBit = idx;
                ans[idx] = 1;
            }
            else {
                ans[idx] = ans[idx - highBit] + 1;
            }
        }
        return ans;
    }

};