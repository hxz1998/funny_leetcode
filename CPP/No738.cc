/**
 * Created by Xiaozhong on 2020/11/29.
 * Copyright (c) 2020/11/29 Xiaozhong. All rights reserved.
 */
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string sn = to_string(N);
        int j = sn.size();
        for (int i = sn.size() - 1; i > 0; --i) {
            if (sn[i] >= sn[i - 1]) continue;
            sn[i - 1]--;
            j = i;
        }
        while (j < sn.size()) sn[j++] = '9';
        return stoi(sn);
    }
};

int main() {
    Solution s;
    cout << s.monotoneIncreasingDigits(332) << endl;
    cout << s.monotoneIncreasingDigits(1234) << endl;
}