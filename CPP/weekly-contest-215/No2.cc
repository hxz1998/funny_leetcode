/**
 * Created by Xiaozhong on 2020/11/15.
 * Copyright (c) 2020/11/15 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        if (n1 != n2) return false;
        vector<int> mapper1(26), mapper2(26);
        unordered_set<char> set1, set2;
        for (int i = 0; i < n1; ++i) {
            char c1 = word1[i], c2 = word2[i];
            mapper1[c1 - 'a']++;
            mapper2[c2 - 'a']++;
            set1.insert(c1);
            set2.insert(c2);
        }
        sort(mapper1.begin(), mapper1.end());
        sort(mapper2.begin(), mapper2.end());
        return set1 == set2 && mapper1 == mapper2;
    }
};

int main() {
    Solution s;
    cout << s.closeStrings("abc", "cba") << endl;
    cout << s.closeStrings("cabbba", "abbccc") << endl;
    cout << s.closeStrings("cabbba", "aabbss") << endl;
    cout << s.closeStrings("uau", "ssx") << endl;
}