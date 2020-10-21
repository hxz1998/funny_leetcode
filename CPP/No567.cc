/**
 * Created by Xiaozhong on 2020/10/20.
 * Copyright (c) 2020/10/20 Xiaozhong. All rights reserved.
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    inline bool match(const vector<int> &s1map, const vector<int> &s2map) {
        for (int i = 0; i < 26; ++i) {
            if (s1map[i] != s2map[i]) return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> s1map(26);
        for (const char &c : s1) s1map[c - 'a']++;

        for (int i = 0; i <= s2.length() - s1.length(); ++i) {
            vector<int> s2map(26);
            for (int j = 0; j < s1.length(); ++j) {
                s2map[s2[i + j] - 'a']++;
            }
            if (match(s1map, s2map)) return true;
        }
        return false;
    }
};

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution s;
    cout << s.checkInclusion(s1, s2) << endl;
    s1 = "adc";
    s2 = "dcda";
    cout << s.checkInclusion(s1, s2);
}
