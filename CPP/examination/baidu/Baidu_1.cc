/**
 * Created by Xiaozhong on 2022/4/19.
 * Copyright (c) 2022/4/19 Xiaozhong. All rights reserved.
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
    unsigned long long n = 0, p = 0;
    cin >> n;
    cin >> p;
    vector<unsigned long long> heights(n);
    for (int idx = 0; idx < n; ++idx) cin >> heights[idx];
    vector<unsigned long long> positions;
    for (int idx = 0; idx < n; ++idx) {
        if (idx == 0 || idx == n - 1) positions.push_back(heights[idx]);
        else if (heights[idx] < heights[idx + 1] && heights[idx] < heights[idx - 1] ||
                 heights[idx] > heights[idx + 1] && heights[idx] > heights[idx - 1]) {
            positions.push_back(heights[idx]);
        }
    }
    unsigned long long ans = 0;
    n = static_cast<int>(positions.size());
    vector<unsigned long long> dp(n);
    for (int idx = 0; idx < n; ++idx) {
        if (idx == 0 || positions[idx] < positions[idx - 1]) continue;
        else if (idx == n - 1 && positions[idx] > positions[idx - 1]) {
            dp[idx] = min(positions[idx] - positions[idx - 1], p);
        } else if (idx == n - 1 && positions[idx] < positions[idx - 1]) {

        } else {
            dp[idx] = min(min(positions[idx] - positions[idx - 1], p), positions[idx + 1] - positions[idx]);
        }

    }

    for (auto num: dp) ans += num;
    cout << ans;
}