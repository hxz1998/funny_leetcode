/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        ans[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0) ans[i] = ans[i / 2];
            else ans[i] = ans[i - 1] + 1;
        }
        return ans;
    }
};