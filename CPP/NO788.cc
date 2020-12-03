/**
 * Created by Xiaozhong on 2020/12/3.
 * Copyright (c) 2020/12/3 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        // 0, 1, 2, 5, 6, 8, 9 之外就是 3 4 7
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            string s = to_string(i);
            bool ok = s.find(2 + '0') != string::npos || s.find(5 + '0') != string::npos ||
                      s.find(6 + '0') != string::npos || s.find(9 + '0') != string::npos;
            if (s.find(3 + '0') == s.npos && s.find(4 + '0') == s.npos && s.find(7 + '0') == s.npos && ok) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.rotatedDigits(10) << endl;
}