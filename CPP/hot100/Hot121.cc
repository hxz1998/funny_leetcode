/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ms = prices[0];
        int ans = 0;
        for (int idx = 1; idx < prices.size(); ++idx) {
            ms = min(ms, prices[idx]);
            ans = max(prices[idx] - ms, ans);
        }
        return ans;
    }
};