/**
 * Created by Xiaozhong on 2020/11/17.
 * Copyright (c) 2020/11/17 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N));
        int dr[] = {2, 2, 1, 1, -1, -1, -2, -2};
        int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};
        dp[r][c] = 1;
        for (; K > 0; K--) {
            vector<vector<double>> dp2(N, vector<double>(N));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (int direction = 0; direction < 8; ++direction) {
                        int cr = i + dr[direction];
                        int cc = j + dc[direction];
                        if (0 <= cr && cr < N && 0 <= cc && cc < N) {
                            dp2[cr][cc] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
            dp = dp2;
        }
        double ans = 0.0;
        for (vector<double> &row : dp) {
            for (double x : row) ans += x;
        }
        return ans;
    }
};