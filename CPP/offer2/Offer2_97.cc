/**
 * Created by Xiaozhong on 2022/3/15.
 * Copyright (c) 2022/3/15 Xiaozhong. All rights reserved.
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

/*class Solution {
public:
    int numDistinct(string s, string t) {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(t.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) dp[i][n] = 1;
        for (int j = n - 1; j >= 0; --j) {
            for (int i = m - 1; i >= 0; --i) {
                if (s[i] == t[j]) dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                else dp[i][j] = dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = static_cast<int>(s.size()), n = static_cast<int>(t.size());
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1));
        for (int i = 0; i <= m; ++i) dp[i][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.numDistinct("bagbag", "bag");
}