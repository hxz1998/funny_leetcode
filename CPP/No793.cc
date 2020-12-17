/**
 * Created by Xiaozhong on 2020/12/16.
 * Copyright (c) 2020/12/16 Xiaozhong. All rights reserved.
 */

class Solution {
public:
    int preimageSizeFZF(int K) {
        long long left = K, right = 10 * K + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long zmi = zeta(mid);
            if (zmi == K) return 5;
            else if (zmi < K) left = mid + 1;
            else right = mid;
        }
        return 0;
    }

private:
    long long zeta(long long x) {
        if (x == 0) return 0;
        return x / 5 + zeta(x / 5);
    }
};