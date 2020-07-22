/**
 * Created by Xiaozhong on 2020/7/22.
 * Copyright (c) 2020/7/22 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            // 如果当前位不为零了，说明没有了进位，那么就直接就地返回就可以了
            if (digits[i] != 0) return digits;
        }
        // 遍历出来了，说明有了进位，那么就直接弄一个初始值为 0 的长数组，然后第一位置 1
        digits = vector<int>(digits.size() + 1, 0);
        digits[0] = 1;
        return digits;
    }
};

int main(int argc, char **args) {
    Solution s;
    vector<int> digits = {1, 2, 9};
    for (int i : s.plusOne(digits)) {
        cout << i << " ";
    }
}