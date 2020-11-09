/**
 * Created by Xiaozhong on 2020/11/9.
 * Copyright (c) 2020/11/9 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        for (int i = 0; i < n - k - 1; ++i) ans[i] = i + 1;
        int m = 1, l = k + 1;
        for (int i = n - k - 1; i < n; ++i) {
            if ((i - n - k - 1) % 2 == 0) {
                ans[i] = m++;
                ans[i] += n - k - 1;
            } else {
                ans[i] = l--;
                ans[i] += n - k - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ans = s.constructArray(3, 1);
    return 0;
}