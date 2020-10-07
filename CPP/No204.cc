/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) return 0;
        bool is_prime[n];
        for (int i = 0; i < n; i++) is_prime[i] = true;

        for (int i = 2; i * i < n; i++) {
            if (is_prime[i])
                for (int j = i * i; j < n; j += i)
                    is_prime[j] = false;
        }
        int count = 0;
        for (int i = 2; i < n; i++) if (is_prime[i]) count++;
        return count;
    }
};