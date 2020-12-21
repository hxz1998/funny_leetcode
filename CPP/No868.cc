/**
 * Created by Xiaozhong on 2020/12/21.
 * Copyright (c) 2020/12/21 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, count = 0, onenum = 0;
        while (n) {
            count++;
            if ((n & 1) == 1) {
                onenum++;
                if (onenum > 1 && count > ans) ans = count;
                count = 0;
            }
            n >>= 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.binaryGap(5) << endl;
    cout << s.binaryGap(6) << endl;
}