/**
 * Created by Xiaozhong on 2020/10/24.
 * Copyright (c) 2020/10/24 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        if (ops.empty()) return m * n;
        for (const vector<int> &v : ops) {
            m = min(m, v.front());
            n = min(n, v.back());
        }
        return n * m;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ops = {
            {2, 2},
            {3, 3}
    };

    cout << s.maxCount(3, 3, ops) << endl;
}