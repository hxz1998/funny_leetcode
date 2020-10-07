/**
 * Created by Xiaozhong on 2020/9/15.
 * Copyright (c) 2020/9/15 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    string toHex(int num) {
        string ans = "";
        int p = -1; // 当 num 为负数的时候，该数会表示左移次数，因为负数第一位为 1， 左移后会默认补1，这样不会让最后的移位结果成 0
        string hex[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
        if (num == 0) return "0";
        else if (num < 0) p = 8;
        while (num) {
            if (p == 0) break;
            int c = 0;          // 用来取出末尾四位，从而进行映射
            c = num & 0xf;
            ans = hex[c] + ans; // 拼接答案
            num >>= 4;          // 将原来的数除掉 16
            --p;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.toHex(26) << endl;
}