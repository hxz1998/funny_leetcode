/*
 * Created by Xiaozhong on 12/29/2021.
 * Copyright (c) 12/29/2021 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int> &a) {
        int n = a.size();
        vector<int> ans(n, 0);
        if (n == 0) return ans;
        if (n == 1 || n == 2) return {a[1], a[0]};
        vector<int> left(n, 1), right(n, 1);
        left[0] = a[0];
        right[n - 1] = a[n - 1];
        for (int idx = 1; idx < n; ++idx) {
            left[idx] = left[idx - 1] * a[idx];
        }
        for (int idx = n - 2; idx >= 0; --idx) {
            right[idx] = right[idx + 1] * a[idx];
        }
        for (int idx = 0; idx < n; ++idx) {
            if (idx == 0) ans[idx] = right[idx + 1];
            else if (idx == n - 1) ans[idx] = left[idx - 1];
            else ans[idx] = left[idx - 1] * right[idx + 1];
        }
        return ans;
    }
};