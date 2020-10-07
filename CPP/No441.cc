/**
 * Created by Xiaozhong on 2020/9/21.
 * Copyright (c) 2020/9/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "cmath"

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return sqrt(2) * sqrt(n + 0.125) - 0.5;
    }
};

int main() {
    Solution s;
    cout << s.arrangeCoins(5) << endl;
    cout << s.arrangeCoins(8) << endl;
}