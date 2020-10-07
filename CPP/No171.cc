/**
 * Created by Xiaozhong on 2020/8/17.
 * Copyright (c) 2020/8/17 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "math.h"

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0, times = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            sum += pow(26, times++) * (s[i] - 'A' + 1);
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.titleToNumber("ZY") << endl;
}