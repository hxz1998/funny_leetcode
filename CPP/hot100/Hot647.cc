/**
 * Created by Xiaozhong on 2022/2/26.
 * Copyright (c) 2022/2/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"

using namespace std;

class Solution {
private:
    int expandFromCenter(const string &str, int left, int right) {
        int ans = 0, n = str.length();
        while (left >= 0 && right < n) {
            if (str[left--] == str[right++]) ans++;
            else break;
        }
        return ans;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int idx = 0; idx < s.size(); ++idx) {
            int odd = expandFromCenter(s, idx, idx);
            int even = expandFromCenter(s, idx, idx + 1);
            ans += (odd + even);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countSubstrings("aaa") << endl << s.countSubstrings("abc") << endl;
    cout << s.countSubstrings("a") << endl;
}
