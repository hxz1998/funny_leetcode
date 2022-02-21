/**
 * Created by Xiaozhong on 2022/2/1.
 * Copyright (c) 2022/2/1 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() <= 1) return "";
        string ans;
        for (int start = 0; start < s.length(); ++start) {
            int lower = 0;
            int upper = 0;
            for (int end = start; end < s.length(); ++end) {
                if (islower(s[end])) lower |= 1 << (s[end] - 'a');
                else if (isupper(s[end])) upper |= 1 << (s[end] - 'A');
                if ((lower ^ upper) == 0 && end - start + 1 > ans.length()) ans = s.substr(start, end - start + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.longestNiceSubstring("YazaAay");
}