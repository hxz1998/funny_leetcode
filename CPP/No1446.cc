/**
 * Created by Xiaozhong on 2021/12/1.
 * Copyright (c) 2021/12/1 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        char prev = s[0];
        int cnt = 1;
        int idx = 1;
        int ans = 0;
        while (idx < s.size()) {
            if (prev == s[idx]) cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 0;
                prev = s[idx];
            }
            idx++;
        }
        return max(ans, cnt);
    }
};

int main() {
    Solution s;
    cout << s.maxPower("leetcode") << endl;
}
