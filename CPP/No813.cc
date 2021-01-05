/**
 * Created by Xiaozhong on 2020/12/30.
 * Copyright (c) 2020/12/30 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int> &A, int K) {
        int n = A.size();
        vector<double> P(n + 1);
        for (int i = 0; i < n; ++i) {
            P[i + 1] = P[i] + A[i];
        }
        vector<double> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = (P[n] - P[i]) / (n - i);
        }
        for (int k = 0; k < K - 1; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    dp[i] = max(dp[i], (P[j] - P[i]) / (j - i) + dp[j]);
                }
            }
        }
        return dp.front();
    }
};