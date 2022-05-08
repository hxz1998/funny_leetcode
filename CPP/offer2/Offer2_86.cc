/**
 * Created by Xiaozhong on 2022/5/6.
 * Copyright (c) 2022/5/6 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

class Solution {
private:
    void dfs(const vector<vector<bool>> &dp, const string &s, const int &n,
             vector<vector<string>> &ret, vector<string> &buffer, int i) {
        if (i == n) {
            ret.push_back(buffer);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (dp[i][j]) {
                buffer.push_back(s.substr(i, j - i + 1));
                dfs(dp, s, n, ret, buffer, j + 1);
                buffer.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int right = 0; right < n; ++right) {
            for (int left = 0; left <= right; ++left) {
                dp[left][right] = s[left] == s[right] && (right - left < 2 || dp[left + 1][right - 1]);
            }
        }
        vector<vector<string>> ret;
        vector<string> buffer;
        dfs(dp, s, n, ret, buffer, 0);
        return ret;
    }
};

int main() {
    Solution s;
    s.partition("google");
}
