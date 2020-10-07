/**
 * Created by Xiaozhong on 2020/8/26.
 * Copyright (c) 2020/8/26 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        /**
         * 定义三种状态，0：不持股，1：持股，2：冷冻期
         * 那么：
         *  不持股的下个状态，   要么继续不持股，或者持股卖出去得现金 prices[i]
         *  持股的下个状态，    要么继续持股，要么就从冷冻期买进来
         *  冷冻期的下一个状态   只能是不持股的上一个状态
         *  之所以让持股的初始状态为 -prices[0] 是因为要买进股票
         *  最后必须卖出去，手里不能有股票，才能获得最大值，所以从 0，2 状态中取最大值
         */
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
            dp[i][2] = dp[i - 1][0];
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]);
    }
};

int main() {
    Solution s;
    vector<int> prices = {1, 2, 3};
    s.maxProfit(prices);
}