/**
 * Created by Xiaozhong on 2021/12/19.
 * Copyright (c) 2021/12/19 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) {
        string ans;
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == spaces[idx]) {
                idx++;
                ans.push_back(' ');
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> sp = {1, 5, 7, 9};
    cout << s.addSpaces("icodeinpython", sp);
}