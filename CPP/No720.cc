/**
 * Created by Xiaozhong on 2020/11/24.
 * Copyright (c) 2020/11/24 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestWord(vector<string> &words) {
        string ans;
        unordered_set<string> wordSet;
        for (auto &word : words) wordSet.insert(word);
        for (auto &word : words) {
            if (word.length() > ans.length() || word.length() == ans.length() && word < ans) {
                bool good = true;
                for (int k = 1; k < word.length(); ++k) {
                    if (!wordSet.count(word.substr(0, k))) {
                        good = false;
                        break;
                    }
                }
                if (good) ans = word;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    cout << s.longestWord(words) << endl;
}