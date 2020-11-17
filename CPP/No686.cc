/**
 * Created by Xiaozhong on 2020/11/16.
 * Copyright (c) 2020/11/16 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans = b.length() / a.length();
        string suffix = a;
        for (int i = 1; i <= ans + 2; ++i) {
            if (i >= ans && a.find(b) != a.npos) return i;
            a.append(suffix);
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.repeatedStringMatch("abc", "abc") << endl;
    cout << s.repeatedStringMatch("abcd", "cdabcdab") << endl;
    cout << s.repeatedStringMatch("abc", "cabcabca") << endl;
}