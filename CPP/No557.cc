/**
 * Created by Xiaozhong on 2020/10/18.
 * Copyright (c) 2020/10/18 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    void reverse(string &s, int start, int end) {
        while (start < end) {
            char t = s[start];
            s[start] = s[end];
            s[end] = t;
            ++start;
            --end;
        }
    }

public:
    string reverseWords(string s) {
        int start = 0;
        for (int end = 0; end < s.length(); ++end) {
            if (s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }
        reverse(s, start, s.length() - 1);
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest");

}