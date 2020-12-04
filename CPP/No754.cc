/**
 * Created by Xiaozhong on 2020/12/4.
 * Copyright (c) 2020/12/4 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target > 0) {
            target -= ++k;
        }
        // 此时 target 已经变成了 delta
        return target % 2 == 0 ? k : k + 1 + k % 2;
    }
};

int main() {
    Solution s;
    cout << s.reachNumber(3) << endl;
    cout << s.reachNumber(1) << endl;
}