/**
 * Created by Xiaozhong on 2022/2/6.
 * Copyright (c) 2022/2/6 Xiaozhong. All rights reserved.
 */

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k == 0) return 0;
        if (k == 1) return 1;
        int a = 1, b = 1;
        while (b <= k) {
            b = a + b;
            a = b - a;
        }
        return findMinFibonacciNumbers(k - a) + 1;
    }
};