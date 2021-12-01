/*
 * Created by Xiaozhong on 11/30/2021.
 * Copyright (c) 11/30/2021 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        if (s.empty()) return s;
        int spaceCount = 0;
        for (char c: s) if (c == ' ') spaceCount++;
        char res[s.size() + spaceCount * 3 + 1];
        int idx = 0;
        for (char c: s) {
            if (c == ' ') {
                res[idx++] = '%';
                res[idx++] = '2';
                res[idx++] = '0';
            } else res[idx++] = c;
        }
        res[idx] = '\0';
        string ans(res);
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.replaceSpace("   ") << endl;
    cout << s.replaceSpace("We are happy.") << endl;
}