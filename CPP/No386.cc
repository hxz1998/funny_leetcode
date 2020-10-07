/**
 * Created by Xiaozhong on 2020/9/9.
 * Copyright (c) 2020/9/9 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    vector<int> ans;

    void dfs(int maxValue, int num, int start) {
        if (num > maxValue) return;
        if (num > 0) ans.push_back(num);
        for (int i = start > 0 ? 0 : 1; i <= 9; ++i) dfs(maxValue, num * 10 + i, start + 1);
    }

public:
    vector<int> lexicalOrder(int n) {
        dfs(n, 0, 0);
        return ans;
    }
};
