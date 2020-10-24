/**
 * Created by Xiaozhong on 2020/10/24.
 * Copyright (c) 2020/10/24 Xiaozhong. All rights reserved.
 */
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>> &clips, int T) {
        vector<int> dp(T + 1, INT32_MAX - 1);
        sort(clips.begin(), clips.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });
        dp[0] = 0;
        for (int i = 1; i <= T; ++i) {
            for (auto &it : clips) {
                if (it[0] < i && it[1] >= i) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }
        return dp[T] == INT32_MAX - 1 ? -1 : dp[T];
    }
};

int main() {
    Solution s;
    vector<vector<int>> clips = {
            {0, 2},
            {4, 6},
            {8, 10},
            {1, 9},
            {1, 5},
            {5, 9}
    };
    cout << s.videoStitching(clips, 10) << endl;
}