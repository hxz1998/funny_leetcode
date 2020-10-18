/**
 * Created by Xiaozhong on 2020/10/18.
 * Copyright (c) 2020/10/18 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        if (s.empty()) return ans;
        for (int left = 0; left < s.length(); ++left) {
            int right = s.rfind(s[left]);
            if (right != left) {
                ans = max(right - left - 1, ans);
            }
        }
        return ans;
    }
};

int main() {
    string s = "cabbac";
    Solution solution;
    cout << solution.maxLengthBetweenEqualCharacters(s) << endl;
    s = "cbzxy";
    cout << solution.maxLengthBetweenEqualCharacters(s) << endl;
    s = "abca";
    cout << solution.maxLengthBetweenEqualCharacters(s) << endl;
    s = "aa";
    cout << solution.maxLengthBetweenEqualCharacters(s) << endl;
}