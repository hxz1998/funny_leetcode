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

/*class Solution {
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
};*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) {
            return lhs.length() == rhs.length() ? false : lhs.length() <= rhs.length();
        });
        vector<int> cnt(26, 0);
        covert(cnt, licensePlate);
        for (const string &word: words) {
            vector<int> tmp(26, 0);
            covert(tmp, word);
            if (check(cnt, tmp)) return word;
        }
        return "";
    }

private:
    bool check(const vector<int> &lhs, const vector<int> &rhs) {
        // lhs 代表 licensePlate 里面的单词计数
        for (int idx = 0; idx < 26; ++idx) if (lhs[idx] > rhs[idx]) return false;
        return true;
    }

    void covert(vector<int> &container, const string &word) {
        if (container.size() < 26) return;
        for (char c: word) {
            if (c >= 'a' && c <= 'z') container[c - 'a']++;
            else if (c >= 'A' && c <= 'Z') container[c - 'A']++;
        }
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