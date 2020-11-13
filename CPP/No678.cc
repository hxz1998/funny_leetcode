/**
 * Created by Xiaozhong on 2020/11/13.
 * Copyright (c) 2020/11/13 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        vector<int> left, star;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') left.push_back(i);
            else if (s[i] == '*') star.push_back(i);
            else {
                if (left.size() > 0) left.pop_back();
                else if (star.size() > 0) star.pop_back();
                else return false;
            }
        }
        if (left.size() > star.size()) return false;
        for (int i = left.size() - 1; i >= 0; --i) {
            if (star.back() < left.back()) return false;
            star.pop_back();
            left.pop_back();
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.checkValidString("(*)") << endl;
    cout << s.checkValidString("()") << endl;
    cout << s.checkValidString("(*()") << endl;
}