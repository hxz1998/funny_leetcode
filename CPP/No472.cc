/**
 * Created by Xiaozhong on 2021/12/28.
 * Copyright (c) 2021/12/28 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
private:
    struct Trie {
        bool isEnd;
        vector<Trie *> children;

        Trie() {
            isEnd = false;
            children = vector<Trie *>(26, nullptr);
        }
    };

    Trie *trie = new Trie();
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) {
            return lhs.length() < rhs.length();
        });
        vector<string> ans;
        for (string &word : words) {
            if (word.empty()) continue;
            if (dfs(word, 0)) ans.emplace_back(word);
            insert(word);
        }
        return ans;
    }

private:
    bool dfs(const string &word, int start) {
        if (word.size() == start) return true;
        Trie *node = trie;
        for (int i = start; i < word.size(); ++i) {
            char ch = word[i];
            int idx = ch - 'a';
            node = node->children[idx];
            if (node == nullptr) return false;
            else if (node->isEnd) {
                if (dfs(word, i + 1)) return true;
            }
        }
        return false;
    }

    void insert(const string &word) {
        Trie *node = trie;
        for (char ch: word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
};