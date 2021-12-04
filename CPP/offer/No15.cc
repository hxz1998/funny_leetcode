/*
 * Created by Xiaozhong on 12/2/2021.
 * Copyright (c) 12/2/2021 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans += (1 << i) & n;
        }
        return ans;
    }
};

int main() {

}