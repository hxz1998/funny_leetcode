/**
 * Created by Xiaozhong on 2020/9/12.
 * Copyright (c) 2020/9/12 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) return 1;
        int x = 1, y = 0;
        for (char c : s) {
            switch (c) {
                case 'A':
                    x = 2 * x + y;
                    break;
                case 'B':
                    y = 2 * y + x;
                    break;
            }
        }
        return x + y;
    }
};

int main() {
    Solution s;
    cout << s.calculate("AB");
}
