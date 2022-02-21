/**
 * Created by Xiaozhong on 2022/1/16.
 * Copyright (c) 2022/1/16 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int base = n / 7;
        return base + n % 7;
    }
};

int main() {
    Solution s;
    cout << s.totalMoney(4) << endl;
    cout << s.totalMoney(10) << endl;
    cout << s.totalMoney(20) << endl;
}