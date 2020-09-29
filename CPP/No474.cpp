/**
 * Created by Xiaozhong on 2020/9/29.
 * Copyright (c) 2020/9/29 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> counter(const string &s) {
        vector<int> count(2, 0);
        for (char c : s) {
            ++count[c - '0'];
        }
        return count;
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (const string &s : strs) {
            vector<int> count = counter(s);
            for (int zeros = m; zeros >= count[0]; --zeros) {
                for (int ones = n; ones >= count[1]; --ones) {
                    dp[zeros][ones] = max(1 + dp[zeros - count[0]][ones - count[1]],
                                          dp[zeros][ones]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    vector<string> strs = {
            "10", "0001", "111001", "1", "0"
    };
    cout << s.findMaxForm(strs, 5, 3) << endl;
}
