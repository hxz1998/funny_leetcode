/**
 * Created by Xiaozhong on 2020/11/28.
 * Copyright (c) 2020/11/28 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int count(string &sequence, string &word, int start) {
        int idx = 0, ret = 0, n = word.size();
        for (int i = start; i <= sequence.length() - n; i += n) {
            if (word == sequence.substr(i, n)) ++ret;
            else return ret;
        }
        return ret;
    }

public:
    int maxRepeating(string sequence, string word) {
        if (sequence.size() < word.size()) return 0;
        int ans = 0;
        for (int i = 0; i < sequence.size(); ++i) {
            if (word.front() == sequence[i]) {
                ans = max(ans, count(sequence, word, i));
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string sequence = "ababc", word = "ac";
    cout << s.maxRepeating(sequence, word) << endl;
    sequence = "ababc", word = "ba";
    cout << s.maxRepeating(sequence, word) << endl;
    sequence = "ababc", word = "ab";
    cout << s.maxRepeating(sequence, word) << endl;
    sequence = "a", word = "absdfas";
    cout << s.maxRepeating(sequence, word) << endl;
    sequence = "aaa", word = "a";
    cout << s.maxRepeating(sequence, word) << endl;
    sequence = "baba", word = "b";
    cout << s.maxRepeating(sequence, word) << endl;
}