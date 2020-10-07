/**
 * Created by Xiaozhong on 2020/8/24.
 * Copyright (c) 2020/8/24 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counter(26, 0);
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++) {
            counter[s[i] - 'a']--;
            counter[t[i] - 'a']++;
        }
        for (int i : counter) if (i) return false;
        return true;
    }
};

int main() {
    string s1 = "anagramb", s2 = "nagarama";
    Solution s;
    cout << s.isAnagram(s1, s2) << endl;
}