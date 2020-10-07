/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        int len = primes.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        vector<int> index(len, 0);

        for (int i = 1; i < n; i++) {
            int min_num = INT32_MAX;
            // 找到下一个丑数
            for (int j = 0; j < len; j++) {
                min_num = min(min_num, dp[index[j]] * primes[j]);
            }
            dp[i] = min_num;
            // 更新 index
            for (int j = 0; j < len; j++) {
                if (min_num == dp[index[j]] * primes[j]) index[j]++;
            }
        }
        return dp[n - 1];
    }
};

int main() {
    vector<int> primes = {2, 7, 13, 19};
    Solution s;
    cout << s.nthSuperUglyNumber(1, primes);
}
