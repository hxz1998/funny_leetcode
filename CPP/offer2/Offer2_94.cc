/**
 * Created by Xiaozhong on 2022/3/17.
 * Copyright (c) 2022/3/17 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<bool>> palindromes(n, vector<bool>(n));
        // 由于状态 palindromes[l][r] palindromes[l][r]
        // 依赖于状态 palindromes[l + 1][r - 1] palindromes[l+1][r−1]，
        // 因此需要我们左端点 left 是「从大到小」进行遍历；而右端点 right 是「从小到大」进行遍历。
        // 一定要从右边往左开始遍历
        for (int left = n - 1; left >= 0; --left) {
            palindromes[left][left] = true;
            for (int right = left + 1; right < n; ++right) {
                palindromes[right][right] = true;
                if (s[left] == s[right])
                    palindromes[left][right] = right - left == 1 || palindromes[left + 1][right - 1];
            }
        }
        vector<int> dp(n, n);
        for (int idx = 0; idx < n; ++idx) dp[idx] = idx;
        for (int idx = 1; idx < n; ++idx) {
            if (palindromes[0][idx]) {
                dp[idx] = 0;
                continue;
            }
            for (int split = 0; split < idx; ++split) {
                if (palindromes[split + 1][idx]) dp[idx] = min(dp[idx], dp[split] + 1);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    cout << s.minCut("abbab") << endl;
}