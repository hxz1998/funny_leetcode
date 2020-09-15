/**
 * Created by Xiaozhong on 2020/9/15.
 * Copyright (c) 2020/9/15 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hashCount(52, 0);
        for (int i = 0; i < s.size(); ++i) {
            if ('a' <= s[i] && s[i] <= 'z') {
                hashCount[s[i] - 'a']++;
            } else {
                hashCount[s[i] - 'A' + 26]++;
            }
        }
        int sum = 0;
        for (int i = 0; i < 52; ++i) {
            if ((sum & 1) && (hashCount[i] & 1)) {
                sum += hashCount[i] - 1;
            } else {
                sum += hashCount[i];
            }
        }
        return sum;
    }
};