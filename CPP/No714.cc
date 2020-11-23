/**
 * Created by Xiaozhong on 2020/11/23.
 * Copyright (c) 2020/11/23 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            // 把手上的股票卖出，或者保持不变
            cash = max(cash, hold + prices[i] - fee);
            // 保持不变，或者买入今天的股票
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};