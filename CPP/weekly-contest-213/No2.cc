/**
 * Created by Xiaozhong on 2020/11/1.
 * Copyright (c) 2020/11/1 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        return (4 + n) * (3 + n) * (2 + n) * (n + 1) / 24;
    }
};

int main() {
    Solution s;
    cout << s.countVowelStrings(33);
}