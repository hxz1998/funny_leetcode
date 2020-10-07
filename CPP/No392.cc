/**
 * Created by Xiaozhong on 2020/9/10.
 * Copyright (c) 2020/9/10 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (j < t.size() && i < s.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};

int main() {
    Solution s;
    cout << s.isSubsequence("acb", "ahbgdc") << endl;

}