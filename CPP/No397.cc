/**
 * Created by Xiaozhong on 2020/9/13.
 * Copyright (c) 2020/9/13 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT32_MAX) return 32;
        int ans = 0;
        while (n > 1) {
            if (n & 1) {
                if (((n + 1) & 3) == 0 && n != 3) {
                    n = n / 2 + 1;
                    ++ans;
                } else {
                    --n;
                }
            } else {
                n /= 2;
            }
            ++ans;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.integerReplacement(7) << endl;
    cout << (3 & 3) << endl << (7 & 3) << endl << (14 & 3) << endl;
}
