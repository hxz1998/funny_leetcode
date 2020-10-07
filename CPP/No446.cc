/**
 * Created by Xiaozhong on 2020/9/23.
 * Copyright (c) 2020/9/23 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "unordered_map"

typedef long long ll;
using namespace std;

typedef long long ll;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        ll ans = 0;
        vector<unordered_map<ll, int>> cnt(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ll delta = (ll) A[i] - (ll) A[j];
                int sum = 0;
                if (cnt[j].find(delta) != cnt[j].end()) {
                    sum += cnt[j][delta];
                }
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        }
        return (int) ans;
    }
};