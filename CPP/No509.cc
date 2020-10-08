/**
 * Created by Xiaozhong on 2020/10/8.
 * Copyright (c) 2020/10/8 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        return fib(N - 1) + fib(N - 2);
    }
};

int main() {
    Solution s;
    cout << s.fib(4) << endl;
}