/**
 * Created by Xiaozhong on 2020/10/11.
 * Copyright (c) 2020/10/11 Xiaozhong. All rights reserved.
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int max_count = INT32_MIN, count = 0;
        for (char &c : s) {
            if (c == '(') ++count;
            else if (c == ')') --count;
            max_count = max(max_count, count);
        }
        return max_count;
    }
};

int main() {
    Solution s;
    cout << s.maxDepth("(1+(2*3)+((8)/4))+1") << endl;
    cout << s.maxDepth("(1)+((2))+(((3)))") << endl;
    cout << s.maxDepth("1+(2*3)/(2-1)") << endl;
    cout << s.maxDepth("1") << endl;
}