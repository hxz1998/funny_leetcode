/**
 * Created by Xiaozhong on 2020/8/19.
 * Copyright (c) 2020/8/19 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, power = 31;
        while (n != 0) {
            ans += (n & 1) << power;
            power--;
            n = n >> 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.reverseBits(uint32_t(43261596)) << endl;
}