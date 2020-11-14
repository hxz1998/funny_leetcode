/**
 * Created by Xiaozhong on 2020/11/14.
 * Copyright (c) 2020/11/14 Xiaozhong. All rights reserved.
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    bool check(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int length = s.length();
        int left = 0, right = length - 1;
        while (left < right) {
            if (s[left] != s[right])
                return check(s, left, right - 1) || check(s, left + 1, right);
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("aba") << endl;
    cout << s.validPalindrome("abca") << endl;
    cout << s.validPalindrome("abcca") << endl;
    cout << s.validPalindrome("aaa") << endl;
    cout << s.validPalindrome("abcd") << endl;
}