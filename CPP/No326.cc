/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
//        return n > 0 && (1162261467 % n == 0);
        if (n <= 0) return false;
        while (n != 0 && n != 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfThree(3) << endl;
    cout << s.isPowerOfThree(10);
}