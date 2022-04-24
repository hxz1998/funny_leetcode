/**
 * Created by Xiaozhong on 2022/4/24.
 * Copyright (c) 2022/4/24 Xiaozhong. All rights reserved.
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

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> nums(n);
    for (int idx = 0; idx < n; ++idx) {
        cin >> nums[idx];
    }
    int ans = 100;
    // dp[idx][0] 和 dp[idx][1] 代表 idx 天，购买了一支股票（如果可以）持有的股票数目，和现金数目
    // dp[idx][2] 和 dp[idx][3] 代表 idx 天，出售了一支股票（如果可以）持有的股票数目，和现金数目
    vector<vector<int>> dp(n + 1, vector<int>(4));
    dp[0][1] = m;
    cout << ans;
}