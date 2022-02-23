/**
 * Created by Xiaozhong on 2020/11/17.
 * Copyright (c) 2020/11/17 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

/*
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
};*/

class Solution {
private:
    vector<vector<int>> dirs = {{1, 2},
                                {2, 1},
                                {2, -1},
                                {1, -2},
                                {-1, -2},
                                {-2, -1},
                                {-2, 1},
                                {-1, 2}};
public:
    double knightProbability(int n, int k, int row, int column) {
        // dp[step][x][y] 从 x，y 走 step 步，还在棋盘上的概率
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for (int step = 0; step <= k; ++step) {
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (step == 0) dp[step][x][y] = 1;
                    else {
                        for (vector<int> dir: dirs) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n) dp[step][x][y] += dp[step - 1][nx][ny] / 8.0;
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};