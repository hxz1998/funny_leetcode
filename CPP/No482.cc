/**
 * Created by Xiaozhong on 2020/10/1.
 * Copyright (c) 2020/10/1 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if (S.empty()) return "";
        stack<char> stk;
        for (char &c : S) if (c != '-') stk.push(c);

        int cnt = 0;
        string ans = "";
        while (!stk.empty()) {
            ans.push_back(toupper(stk.top()));
            ++cnt;
            stk.pop();
            if (cnt % K == 0 && stk.size() != 0) ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s = "abcdedf";
    Solution solution;
    cout << solution.licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;
    cout << solution.licenseKeyFormatting("2-5g-3-J", 2);

}