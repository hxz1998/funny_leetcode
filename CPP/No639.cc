/**
 * Created by Xiaozhong on 2020/10/31.
 * Copyright (c) 2020/10/31 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int mod = 1000000007;

    int ways(const string &s, int i, vector<int> &memo) {
        if (i < 0) return 1;
        if (memo[i]) return memo[i];
        if (s[i] == '*') {
            long long res = 9 * ways(s, i - 1, memo);
            if (i > 0 && s[i - 1] == '1') res = (res + 9 * ways(s, i - 2, memo)) % mod;
            else if (i > 0 && s[i - 1] == '2') res = (res + 6 * ways(s, i - 2, memo)) % mod;
            else if (i > 0 && s[i - 1] == '*') res = (res + 15 * ways(s, i - 2, memo)) % mod;
            memo[i] = (int) res;
            return memo[i];
        }
        long res = s[i] != '0' ? ways(s, i - 1, memo) : 0;
        if (i > 0 && s[i - 1] == '1') res = (res + ways(s, i - 2, memo)) % mod;
        else if (i > 0 && s[i - 1] == '2' && s[i] <= '6') res = (res + ways(s, i - 2, memo)) % mod;
        else if (i > 0 && s[i - 1] == '*') res = (res + (s[i] <= '6' ? 2 : 1) * ways(s, i - 2, memo));
        memo[i] = (int) res;
        return memo[i];
    }

public:
    int numDecodings(string s) {
        vector<int> memo(s.length(), 0);
        return ways(s, s.length() - 1, memo);
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("1*") << endl;
}