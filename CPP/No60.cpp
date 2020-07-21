/**
 * Created by Xiaozhong on 2020/7/21.
 * Copyright (c) 2020/7/21 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 俏皮解法，不算数！
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = string("123456789").substr(0, n);
        for (int i = 1; i < k; i++) next_permutation(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3, 3);
}
