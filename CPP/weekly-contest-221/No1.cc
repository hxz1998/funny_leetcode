/**
 * Created by Xiaozhong on 2020/12/27.
 * Copyright (c) 2020/12/27 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowel;
        vowel.insert({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int sum = 0, n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            if (vowel.find(s[i]) != vowel.end()) sum++;
        }
        for (int i = n / 2; i < n; ++i) {
            if (vowel.find(s[i]) != vowel.end()) sum--;
        }
        return sum == 0;
    }
};

int main() {
    Solution s;
    cout << s.halvesAreAlike("book") << endl;
    cout << s.halvesAreAlike("textbook") << endl;
    cout << s.halvesAreAlike("MerryChristmas") << endl;
    cout << s.halvesAreAlike("AbCdEfGh") << endl;
}