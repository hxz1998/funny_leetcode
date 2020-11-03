/**
 * Created by Xiaozhong on 2020/11/3.
 * Copyright (c) 2020/11/3 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int sz = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(sz, 1);
        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = 0;
        for (int x : dp) ans = max(x, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> pairs = {
            {1, 2},
            {2, 3},
            {3, 4}
    };
    cout << s.findLongestChain(pairs);
}