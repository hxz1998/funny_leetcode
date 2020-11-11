/**
 * Created by Xiaozhong on 2020/11/11.
 * Copyright (c) 2020/11/11 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        // 找规律题目
        /*if (n == 0) return 0;
        if (n >= 3) return min(8, 3 * m + 1);
        if (n == 1) return min(2, 1 + m);
        if (n == 2) return min(4, 1 + 2 * m);*/
        /**
         * 经过优化后，是这样的：
         */
        n = min(n, 3);
        return min(1 << n, 1 + m * n);
    }
};

int main() {
    Solution s;
    cout << s.flipLights(1, 1) << endl;
}