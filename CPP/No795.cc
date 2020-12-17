/**
 * Created by Xiaozhong on 2020/12/17.
 * Copyright (c) 2020/12/17 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }

private:
    int count(vector<int> &A, int bound) {
        int ans = 0, cur = 0;
        for (int x : A) {
            cur = x <= bound ? cur + 1 : 0;
            ans += cur;
        }
        return ans;
    }
};