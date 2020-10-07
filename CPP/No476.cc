/**
 * Created by Xiaozhong on 2020/9/30.
 * Copyright (c) 2020/9/30 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int n = num, count = 0;
        while (n) {
            ++count;
            n >>= 1;
        }
        return num ^ ((long) (1 << count) - 1);
    }
};

int main() {
    Solution s;
    cout << s.findComplement(5) << endl;
    cout << s.findComplement(1) << endl;
}