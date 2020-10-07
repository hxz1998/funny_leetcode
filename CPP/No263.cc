/**
 * Created by Xiaozhong on 2020/8/24.
 * Copyright (c) 2020/8/24 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        if (num == 1 || num == 2 || num == 3 || num == 5) return true;
        if (num % 2 == 0 && isUgly(num / 2) ||
            num % 3 == 0 && isUgly(num / 3) ||
            num % 5 == 0 && isUgly(num / 5))
            return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isUgly(14) << endl << s.isUgly(8) << endl;
}
