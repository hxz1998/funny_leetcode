/**
 * Created by Xiaozhong on 2020/9/28.
 * Copyright (c) 2020/9/28 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    bool helper(int maxChoosableInteger, int desireTotal, vector<bool> dp, int state) {
        if (dp[state]) return dp[state];
        for (int i = 1; i <= maxChoosableInteger; ++i) {
            int cur = 1 << (i - 1);
            if ((cur & state) != 0) continue;

            // 如果当前选择累计和大于等于 desireTotal，那么必赢
            // 或者当前选择之后，另一个人的选择会导致他必输，那么当前也必赢
            if (desireTotal - i <= 0 || !helper(maxChoosableInteger, desireTotal - i, dp, state | cur)) {
                return dp[state] = true;
            }
        }
        // 无论怎样都不能让对方输，那么就是自己输了
        return dp[state] = false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        return helper(maxChoosableInteger, desiredTotal, vector<bool>(1 << maxChoosableInteger), 0);
    }
};