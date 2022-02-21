/**
 * Created by Xiaozhong on 2022/1/27.
 * Copyright (c) 2022/1/27 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) a = string(b.length() - a.length(), '0').append(a);
        else if (b.length() < a.length()) b = string(a.length() - b.length(), '0').append(b);
        int len = a.length();
        string ans;
        int carry = 0;
        for (int idx = len - 1; idx >= 0; --idx) {
            int sum = (a[idx] - '0') + (b[idx] - '0');
            ans = to_string((carry + sum) % 2).append(ans);
            carry = (carry + sum) / 2;
        }
        if (carry > 0) ans = '1' + ans;
        return ans;
    }
};

int main() {

    Solution s;
    cout << s.addBinary("1", "111") << endl;
    cout << s.addBinary("11", "10") << endl;
    cout << s.addBinary("1010", "1011") << endl;
}