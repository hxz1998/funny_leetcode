/**
 * Created by Xiaozhong on 2020/12/1.
 * Copyright (c) 2020/12/1 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    unordered_map<char, int> count(const string &word) {
        unordered_map<char, int> counter;
        for (const char &c : word) {
            if (c >= 'a' && c <= 'z') counter[c]++;
            else if (c >= 'A' && c <= 'Z') counter[c - 'A' + 'a']++;
        }
        return counter;
    }

    bool check(const unordered_map<char, int> &counter, string &word) {
        unordered_map<char, int> word_counter = count(word);
        for (auto iter = counter.begin(); iter != counter.end(); ++iter) {
            if (!word_counter.count(iter->first) || word_counter[iter->first] < iter->second) return false;
        }
        return true;
    }

public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        unordered_map<char, int> counter = count(licensePlate);
        string ans;
        for (auto &word : words) {
            if ((word.length() < ans.length() || ans.length() == 0) && check(counter, word)) ans = word;
        }
        return ans;
    }
};

int main() {
    Solution s;
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    cout << s.shortestCompletingWord(licensePlate, words) << endl;
    licensePlate = "Ah71752";
    words = {"suggest", "letter", "of", "husband", "easy", "education", "drug", "prevent", "writer", "old"};
    cout << s.shortestCompletingWord(licensePlate, words) << endl;
}