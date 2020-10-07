/**
 * Created by Xiaozhong on 2020/8/29.
 * Copyright (c) 2020/8/29 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        // reverse(s.begin(), s.end());
        int left = 0, right = s.size() - 1;
        char c;
        while (left < right) {
            c = s[left];
            s[left++] = s[right];
            s[right--] = c;
        }
    }
};

int main() {
    Solution s;
    vector<char> chars = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(chars);
    for (char c : chars) {
        cout << c << " ";
    }
}