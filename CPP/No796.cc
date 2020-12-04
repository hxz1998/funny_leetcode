/**
 * Created by Xiaozhong on 2020/12/4.
 * Copyright (c) 2020/12/4 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        string AA = A + A;
        return (A.length() != B.length() || AA.find(B) == string::npos) ? false : true;
    }
};

int main() {
    Solution s;
    cout << s.rotateString("aa", "a") << endl;
}