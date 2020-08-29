/**
 * Created by Xiaozhong on 2020/8/29.
 * Copyright (c) 2020/8/29 Xiaozhong. All rights reserved.
 */
#include <cmath>
#include "iostream"

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        // 利用 log(4 ^ n) = n * log(4) 的基本性质结合 int 类型转换会损失小数位来判断
        /*if (num <= 0) return false;
        int n = log(num) / log(4);
        return log(num) == n * log(4);*/

        // 使用位运算来判断，先判断是否是 2 的幂，然后再把不是 4 的幂情况排除出去
        // 2 的倍数在偶数位上均为 1， 4 的倍数在奇数位上均为 1，其他位均为 0
        return num > 0 && (num & (num - 1)) == 0 && (num & 0xaaaaaaaa) == 0;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfFour(16);
}