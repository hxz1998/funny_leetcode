/**
 * Created by Xiaozhong on 2020/10/1.
 * Copyright (c) 2020/10/1 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    int base = 1337;
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for (int i = upper; i >= lower; --i) {
            string temp = to_string(i);
            string rev_temp = temp;
            reverse(rev_temp.begin(), rev_temp.end());
            long long product = stol(temp + rev_temp);
            for (long long j = upper; j * j >= product; --j) {
                if (product % j == 0) {
                    return product % base;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.largestPalindrome(2) << endl;
}