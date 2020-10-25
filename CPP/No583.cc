/**
 * Created by Xiaozhong on 2020/10/26.
 * Copyright (c) 2020/10/26 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;

    int lcs(const string &s1, const string &s2, int i, int j) {
        if (i == 0 || j == 0) return 0;
        if (s1[i - 1] == s2[j - 1]) return 1 + lcs(s1, s2, i - 1, j - 1);
        else return max(lcs(s1, s2, i - 1, j), lcs(s1, s2, i, j - 1));
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        dp.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0) continue;
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return m + n - 2 * dp[m][n];
    }
};

int main() {
    Solution s;
    string word1 = "sea";
    string word2 = "eat";
    cout << s.minDistance(word1, word2) << endl;
}