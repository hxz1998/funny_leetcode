/**
 * Created by Xiaozhong on 2020/12/13.
 * Copyright (c) 2020/12/13 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        if (n % 2 == 0) {
            return n / 2 + numberOfMatches(n / 2);
        } else {
            return (n - 1) / 2 + numberOfMatches((n - 1) / 2 + 1);
        }
    }
};

int main() {
    Solution s;
    cout << s.numberOfMatches(7) << endl;
    cout << s.numberOfMatches(14) << endl;
}