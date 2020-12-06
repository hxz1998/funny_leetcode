/**
 * Created by Xiaozhong on 2020/12/6.
 * Copyright (c) 2020/12/6 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    const int mod = 1e9 + 7;

    short bitCount(int n) {
        short width = 0;
        while (n) {
            ++width;
            n >>= 1;
        }
        return width;
    }

public:
    long long concatenatedBinary(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; ++i) {
            short bitWidth = bitCount(i);
            ans %= mod;
            ans <<= bitWidth;
            ans |= i;
        }
        return ans % mod;
    }
};

int main() {
    Solution s;
    cout << s.concatenatedBinary(12) << endl;
    assert(s.concatenatedBinary(12) == 505379714);
}