/**
 * Created by Xiaozhong on 2020/10/10.
 * Copyright (c) 2020/10/10 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        /**
         * 如果：
         *  第一个是大写，那么后面，
         *      要么都是大写
         *      要么没有大写
         *  第一个是小写，那么后面
         *      就不能出现大写
         */
        bool upper_first = true, lower = false, again_upper = false;
        for (int i = 0; i < word.length(); ++i) {
            if (i == 0 && word[i] >= 97 && word[i] <= 122) upper_first = false;
            if (upper_first) {
                if (word[i] < 97 && i != 0) again_upper = true;
                if (word[i] > 97 && word.size() > 2 && i == word.size() - 1 && !lower) return false;
                if (word[i] >= 97 && word[i] <= 122) lower = true;
                if (again_upper && lower) return false;
                if (lower && word[i] < 97) return false;
            } else {
                if (word[i] < 97) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.detectCapitalUse("FlaG") << endl;
    cout << s.detectCapitalUse("USA") << endl;
    cout << s.detectCapitalUse("FFf") << endl;
    cout << s.detectCapitalUse("Afdsf") << endl;
    cout << s.detectCapitalUse("aAFD") << endl;
    cout << s.detectCapitalUse("EEJIHEHEFIEFBBBBaefanfnawjfbawebf") << endl;
}