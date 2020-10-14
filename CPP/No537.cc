/**
 * Created by Xiaozhong on 2020/10/13.
 * Copyright (c) 2020/10/13 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int r1, c1, r2, c2, a1, a2;
        char t;
        stringstream ss1(a);
        stringstream ss2(b);
        ss1 >> r1 >> t >> c1;
        ss2 >> r2 >> t >> c2;

        a1 = r1 * r2 - c1 * c2;
        a2 = r1 * c2 + r2 * c1;
        return to_string(a1) + "+" + to_string(a2) + "i";
    }
};

int main() {
    Solution s;
    cout << s.complexNumberMultiply("0+19i", "1+10i");
}