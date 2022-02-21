/**
 * Created by Xiaozhong on 2022/2/6.
 * Copyright (c) 2022/2/6 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "vector"
#include "functional"

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        function<void(string &, int, int)> rev = [&](string &str, int begin, int end) {
            while (begin < end) {
                char t = str[begin];
                str[begin++] = str[end];
                str[end--] = t;
            }
        };
        for (int idx = 0; idx < word.length(); ++idx) {
            if (word[idx] == ch) {
                rev(word, 0, idx);
                return word;
            }
        }
        return word;
    }
};