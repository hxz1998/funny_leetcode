/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            sum += (n & 1);
            n = n >> 1;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(uint32_t(11));
}