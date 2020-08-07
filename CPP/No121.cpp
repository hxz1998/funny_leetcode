/**
 * Created by Xiaozhong on 2020/8/7.
 * Copyright (c) 2020/8/7 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n) return 0;
        int dp = 0;
        int min_price = prices[0];
        for (int i = 1; i < n; i++) {
            min_price = min(min_price, prices[i]);
            dp = max(dp, prices[i] - min_price);
        }
        return dp;
    }
};

int main(int argc, char **args) {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices);
}