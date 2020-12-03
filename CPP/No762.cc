/**
 * Created by Xiaozhong on 2020/12/2.
 * Copyright (c) 2020/12/2 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isSmallPrime(int x) {
        return x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19;
    }

    int bitCount(int x) {
        int ret = 0;
        while (x) {
            if (x & 1) ++ret;
            x >>= 1;
        }
        return ret;
    }

public:
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int i = L; i <= R; ++i) {
            if (isSmallPrime(bitCount(i))) ++ans;
        }
        return ans;
    }
};