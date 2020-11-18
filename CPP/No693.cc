/**
 * Created by Xiaozhong on 2020/11/18.
 * Copyright (c) 2020/11/18 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev_bit = n & 1, curr_bit;
        n >>= 1;
        while (n) {
            curr_bit = n & 1;
            if (curr_bit == prev_bit) return false;
            prev_bit = curr_bit;
            n >>= 1;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.hasAlternatingBits(5) << endl;
    cout << s.hasAlternatingBits(7) << endl;
    cout << s.hasAlternatingBits(11) << endl;
    cout << s.hasAlternatingBits(10) << endl;
}