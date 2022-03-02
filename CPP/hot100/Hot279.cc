/*
 * Created by Xiaozhong on 3/2/2022.
 * Copyright (c) 3/2/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

// 直接从小到大挨个计算就好了
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int num = 1; num <= n; ++num) {
            int ms = INT32_MAX;
            for (int subNum = 1; subNum * subNum <= num; ++subNum) {
                ms = min(ms, dp[num - subNum * subNum]);
            }
            dp[num] = ms + 1;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
    cout << s.numSquares(13) << endl;
}