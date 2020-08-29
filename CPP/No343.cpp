/**
 * Created by Xiaozhong on 2020/8/29.
 * Copyright (c) 2020/8/29 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    vector<int> memo;

    int helper(int n) {
        if (n == 2) return 1;
        if (memo[n] != 0) return memo[n];
        int res = INT32_MIN;
        for (int i = 1; i < n - 1; i++) {
            res = max(res, max(helper(n - i) * i, i * (n - i)));
        }
        memo[n] = res;
        return res;
    }

public:
    int integerBreak(int n) {
        memo.resize(n + 1);
        // 可以使用记忆化递归来完成
        // return helper(n);
        // 也可以转换成动态规划
        memo[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i - 1; j++) {
                memo[i] = max(memo[i], max(j * memo[i - j], j * (i - j)));
            }
        }
        return memo[n];
    }
};

int main() {
    Solution s;
    cout << s.integerBreak(10);
}