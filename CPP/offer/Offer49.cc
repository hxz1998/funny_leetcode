/*
 * Created by Xiaozhong on 12/14/2021.
 * Copyright (c) 12/14/2021 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for (int i = 1; i < n; ++i) {
            int curr = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
            // 当这里不用else if，就已经跳过了相同值
            if (curr == dp[p2] * 2) p2++;
            if (curr == dp[p3] * 3) p3++;
            if (curr == dp[p5] * 5) p5++;
            dp[i] = curr;
        }
        return dp[n - 1];
    }
};

int main() {
    unordered_set<int> ugly;
    Solution s;
    for (int i = 6; i <= 100; ++i) {
        cout << s.nthUglyNumber(i) << endl;
        ugly.insert(s.nthUglyNumber(i));
    }
    cout << ugly.size() << endl;
}