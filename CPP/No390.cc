/**
 * Created by Xiaozhong on 2020/9/10.
 * Copyright (c) 2020/9/10 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
private:
    int dp(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n & 1) return dp(n - 1);
        else return 2 * (1 + n / 2 - dp(n / 2));
    }

public:
    int lastRemaining(int n) {
        return dp(n);
    }
};

int main() {
    Solution s;
    cout << s.lastRemaining(9) << endl;
}