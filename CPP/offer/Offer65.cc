<<<<<<< HEAD
/*
 * Created by Xiaozhong on 12/23/2021.
 * Copyright (c) 12/23/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
=======
/**
 * Created by Xiaozhong on 2021/12/28.
 * Copyright (c) 2021/12/28 Xiaozhong. All rights reserved.
 */

#include "iostream"
>>>>>>> bbc1b50571b4d1e7c4c8854e2795805f895efacc

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int c = (unsigned int) (a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};