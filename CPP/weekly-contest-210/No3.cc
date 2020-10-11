/**
 * Created by Xiaozhong on 2020/10/11.
 * Copyright (c) 2020/10/11 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        if (a.length() == 1 && b.length() == 1) return true;
        for (int i = 0; i < a.size(); ++i) {
            int pa = 0, pb = b.size() - 1;
            while (pa <= i) if (a[pa++] != b[pb--]) break;
            if (pa == pb + 1) return true;

            pa = a.size() - 1, pb = 0;
            while (pb <= i) if (a[pa--] != b[pb++]) break;
            if (pa == pb - 1) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.checkPalindromeFormation("cdeoo", "oooab") << endl;
    cout << s.checkPalindromeFormation("x", "y") << endl;
}