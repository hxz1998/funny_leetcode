/**
 * Created by Xiaozhong on 2020/10/16.
 * Copyright (c) 2020/10/16 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
public:
    bool checkRecord(string s) {
        int state_a = 0, state_l = 0;
        for (const char &c : s) {
            switch (c) {
                case 'A':
                    if (state_a) return false;
                    else state_a = 1;
                    state_l = 0;
                    break;
                case 'L':
                    state_l++;
                    if (state_l > 2) return false;
                    break;
                case 'P':
                    state_l = 0;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    cout << s.checkRecord("PPALLL") << endl;
}