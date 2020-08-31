/**
 * Created by Xiaozhong on 2020/8/31.
 * Copyright (c) 2020/8/31 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int ans = 10, temp = 9 * 9;
        for (int i = 2; i <= n; i++) {
            ans += temp;
            temp *= 10 - i;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countNumbersWithUniqueDigits(2) << endl;
    cout << s.countNumbersWithUniqueDigits(3) << endl;
}