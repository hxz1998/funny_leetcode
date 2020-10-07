/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) return "0";
        if (n < 1000) return to_string(n);
        string s = to_string(n);
        int times = 0;
        string ans = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            ans.push_back(s[i]);
            if (++times % 3 == 0) {
                if (i != 0) ans.append(".");
                times = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.thousandSeparator(51040) << endl;
    cout << s.thousandSeparator(123456789) << endl;
}