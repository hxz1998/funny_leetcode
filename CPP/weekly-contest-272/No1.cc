/**
 * Created by Xiaozhong on 2021/12/19.
 * Copyright (c) 2021/12/19 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        auto check = [](string &word) {
            int left = 0, right = word.size() - 1;
            while (left < right) {
                if (word[left++] != word[right--]) return false;
            }
            return true;
        };
        for (string &word : words) {
            if (check(word)) return word;
        }
        return "";
    }
};


int main() {

}