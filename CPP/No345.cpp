/**
 * Created by Xiaozhong on 2020/8/29.
 * Copyright (c) 2020/8/29 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"
#include "iostream"


using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.npos) left++;
            while (left < right && vowels.find(s[right]) == vowels.npos) right--;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("hello");
}