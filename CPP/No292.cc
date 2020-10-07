/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};

int main() {
    Solution s;
    cout << s.canWinNim(7);
}