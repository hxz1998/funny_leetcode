/**
 * Created by Xiaozhong on 2021/1/5.
 * Copyright (c) 2021/1/5 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int> &A, int K) {
        int ms = A[0], mx = A[0];
        for (int num : A) {
            ms = min(ms, num);
            mx = max(mx, num);
        }
        return max(0, mx - ms - 2 * K);
    }
};