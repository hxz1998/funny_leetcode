/**
 * Created by Xiaozhong on 2020/9/27.
 * Copyright (c) 2020/9/27 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        int sum = 0;
        while (x) {
            sum += (x & 1);
            x >>= 1;
        }

        return sum;
    }
};

int main() {
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
}