/**
 * Created by Xiaozhong on 2020/12/6.
 * Copyright (c) 2020/12/6 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ret;
        char prev = ' ';
        for (char c : command) {
            if (c == 'G') ret.push_back(c);
            else if (c == ')') {
                if (prev == '(') {
                    ret.push_back('o');
                    prev = ' ';
                } else {
                    ret.append("al");
                }
            }
            prev = c;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.interpret("(al)G(al)()()G") << endl;
    cout << s.interpret("G()()()()(al)") << endl;
    cout << s.interpret("G()(al)") << endl;
}