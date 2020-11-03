/**
 * Created by Xiaozhong on 2020/11/3.
 * Copyright (c) 2020/11/3 Xiaozhong. All rights reserved.
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.length(), ans = 0;
        for (int i = 0; i < 2 * sz - 1; ++i) {
            int left = i / 2, right = i / 2 + i % 2;
            while (left >= 0 && right < sz && s[left] == s[right]) {
                left--;
                right++;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countSubstrings("aaa") << endl;
    cout << s.countSubstrings("abc") << endl;
}