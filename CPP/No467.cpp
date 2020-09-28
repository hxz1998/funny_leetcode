/**
 * Created by Xiaozhong on 2020/9/28.
 * Copyright (c) 2020/9/28 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    bool isContinous(char prev, char curr) {
        if (prev == 'z') return curr == 'a';
        return prev + 1 == curr;
    }

public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int n = p.size();
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && isContinous(p[i - 1], p[i])) {
                ++k;
            } else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};