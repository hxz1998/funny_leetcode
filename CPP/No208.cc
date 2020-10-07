/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include <cstring>
#include "string"
#include "vector"
#include "iostream"

using namespace std;

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Trie {
private:
    bool is_end;
    Trie *next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        is_end = false;
        memset(next, 0, sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return node->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char c : prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return true;
    }
};