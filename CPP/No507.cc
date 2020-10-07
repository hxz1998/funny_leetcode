/**
 * Created by Xiaozhong on 2020/10/7.
 * Copyright (c) 2020/10/7 Xiaozhong. All rights reserved.
 */
#include <iostream>

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= num / 2; ++i) {
            if (num % i == 0) sum += i;
        }
        return num == sum;
    }
};

int main() {
    Solution s;
    std::cout << s.checkPerfectNumber(6) << std::endl;
    std::cout << s.checkPerfectNumber(28) << std::endl;
    std::cout << s.checkPerfectNumber(496) << std::endl;
    std::cout << s.checkPerfectNumber(497) << std::endl;
}