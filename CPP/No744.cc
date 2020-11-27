/**
 * Created by Xiaozhong on 2020/11/27.
 * Copyright (c) 2020/11/27 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        vector<char>::iterator iter = upper_bound(letters.begin(), letters.end(), target);
        if (iter == letters.end()) iter = letters.begin();
        return *iter;
    }
};

int main() {
    Solution s;
    vector<char> letters = {'c', 'f', 'j'};
    cout << s.nextGreatestLetter(letters, 'g') << endl;
    cout << s.nextGreatestLetter(letters, 'j') << endl;
    cout << s.nextGreatestLetter(letters, 'k') << endl;
}