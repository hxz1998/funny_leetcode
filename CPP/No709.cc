/**
 * Created by Xiaozhong on 2020/11/22.
 * Copyright (c) 2020/11/22 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
//        for (char &c : str) c |= 32;
        for (int idx = 0; idx < str.size(); ++idx) {
            if (str[idx] >= 'A' && str[idx] <= 'Z') {
                str[idx] += 32;
            }
        }
        return str;
    }
};