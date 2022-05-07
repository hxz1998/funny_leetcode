/**
 * Created by Xiaozhong on 2022/5/1.
 * Copyright (c) 2022/5/1 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = static_cast<int>(costs.size());
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for (int idx = 1; idx < n; ++idx) {
            dp[idx][0] = min(dp[idx - 1][1], dp[idx - 1][2]) + costs[idx][0];
            dp[idx][1] = min(dp[idx - 1][0], dp[idx - 1][2]) + costs[idx][1];
            dp[idx][2] = min(dp[idx - 1][0], dp[idx - 1][1]) + costs[idx][2];
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};

int main() {
    string msg = "abc bbc edg";
    cout << msg.find(' ') << endl;
    sort(msg.begin(), msg.end(), [](const char &lhs, const char &rhs) {
        return true;
    });
    cout << msg.substr(0, msg.find(' ')) << "-" << msg.substr(msg.find(' ') + 1, msg.size() - msg.find(' ') - 1);
}