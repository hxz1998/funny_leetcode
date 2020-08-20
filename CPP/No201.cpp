/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */
#include "iostream"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m != n) {    // 寻找公共前缀过程
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;  //左移对齐过程
    }
};

int main() {
    Solution s;
    std::cout << s.rangeBitwiseAnd(5, 7);
}