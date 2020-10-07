/**
 * Created by Xiaozhong on 2020/9/28.
 * Copyright (c) 2020/9/28 Xiaozhong. All rights reserved.
 */

// The rand7() API is already defined for you.
// @return a random integer in the range 1 to 7

int rand7();

class Solution {
public:
    int rand10() {
        int n = (rand7() - 1) * 7 + rand7();
        while (n > 10) {
            n = (rand7() - 1) * 7 + rand7();
        }
        return n;
    }
};