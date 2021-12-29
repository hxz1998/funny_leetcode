/**
 * Created by Xiaozhong on 2021/12/28.
 * Copyright (c) 2021/12/28 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT32_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int price = prices[i];
            if (price < minPrice) {
                minPrice = price;
            } else {
                ans = max(ans, price - minPrice);
            }
        }
        return ans;
    }
};