/**
 * Created by Xiaozhong on 2022/2/7.
 * Copyright (c) 2022/2/7 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"
#include "functional"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        function<int(string &, int, int)> expandAroundCenter = [&](string &str, int left, int right) {
            while (left >= 0 && right < str.length() && str[left] == str[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };
        for (int center = 0; center < s.length(); ++center) {
            int odd = expandAroundCenter(s, center - 1, center + 1);
            int even = expandAroundCenter(s, center, center + 1);
            int length = max(odd, even);
            if (length > end - start + 1) {
                start = center - (length - 1) / 2;
                end = center + length / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("cbbd") << endl << s.longestPalindrome("babad") << endl;
}