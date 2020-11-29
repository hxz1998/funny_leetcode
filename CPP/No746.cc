/**
 * Created by Xiaozhong on 2020/11/28.
 * Copyright (c) 2020/11/28 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n);  // 动态规划记录
        dp[0] = cost[0], dp[1] = cost[1]; // 对于前两个状态，自然是以 0 和 1 为出发点得到的消耗
        for (int i = 2; i < n; ++i) {
            // 对于 i ，dp[i] 记录了截止到 i 所要消耗的最小能量
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        // 从最后两个状态中找到最小值
        return min(dp[n - 2], dp[n - 1]);
    }
};

int main() {
    Solution s;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s.minCostClimbingStairs(cost) << endl;
}