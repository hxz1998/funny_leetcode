/**
 * Created by Xiaozhong on 2020/8/24.
 * Copyright (c) 2020/8/24 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // 数学方法：
        // return (num - 1) % 9 + 1;
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum < 10) return sum;
        else return addDigits(sum);
    }
};

int main() {
    Solution s;
    cout << s.addDigits(38) << endl;
}