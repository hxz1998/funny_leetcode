/**
 * Created by Xiaozhong on 2020/10/10.
 * Copyright (c) 2020/10/10 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        return max(a.size(), b.size());
    }
};