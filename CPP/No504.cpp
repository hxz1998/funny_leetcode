/**
 * Created by Xiaozhong on 2020/10/5.
 * Copyright (c) 2020/10/5 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (!num)return "0";
        string ans;
        bool flag = num >= 0;
        num = abs(num);
        while (num != 0) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        return flag ? ans : "-" + ans;
    }
};


int main() {
    Solution s;
    cout << s.convertToBase7(100) << endl;
    cout << s.convertToBase7(-7) << endl;
    cout << s.convertToBase7(7) << endl;
}