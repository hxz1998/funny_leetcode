/**
 * Created by Xiaozhong on 2020/11/13.
 * Copyright (c) 2020/11/13 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MagicDictionary {
private:
    unordered_map<string, int> count;
    unordered_set<string> words;

    vector<string> generalizedNeighbors(string &word) {
        vector<string> ret;
        for (int i = 0; i < word.size(); ++i) {
            char letter = word[i];
            word[i] = '*';
            ret.emplace_back(word);
            word[i] = letter;
        }
        return ret;
    }

public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (string word : dictionary) {
            words.insert(word);
            for (string &neighboor: generalizedNeighbors(word)) {
                if (count.count(neighboor)) {
                    count[neighboor] = count[neighboor] + 1;
                } else {
                    count.insert(make_pair(neighboor, 1));
                }
            }
        }
    }

    bool search(string searchWord) {
        for (string &neighboor:generalizedNeighbors(searchWord)) {
            int c = count[neighboor];
            if (c > 1 || c == 1 && !words.count(searchWord)) return true;
        }
        return false;
    }
};

int main() {
    vector<string> dictionary = {"hello", "hallo", "leetcode"};
    MagicDictionary md;
    md.buildDict(dictionary);
    cout << md.search("hhllo") << endl;
    cout << md.search("hello") << endl;
    cout << md.search("hallo") << endl;
}