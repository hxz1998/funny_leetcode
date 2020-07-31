/**
 * Created by Xiaozhong on 2020/7/31.
 * Copyright (c) 2020/7/31 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        long long c = 1;
        for (int i = 0; i < n; i++) {
            c = c * 2 * (2 * i + 1) / (i + 2);
        }
        return c;
    }
};

int main() {
    Solution s;
    cout << s.numTrees(3) << endl;
}
