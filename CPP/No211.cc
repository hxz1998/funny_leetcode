/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "string"

using namespace std;

struct Trie {
    bool is_end;
    Trie *next[26];

    Trie() {
        is_end = false;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

class WordDictionary {
private:
    Trie *root;

    bool subSearch(Trie *node, string word) {
        if (!node) return false;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    // 遇到通配符 . 时候，对剩下的子串进行递归检查
                    if (subSearch(node->next[j], word.substr(i + 1))) return true;
                }
                return false;
            }
            // 正常的搜索
            if (!node->next[word[i] - 'a']) return false;
            node = node->next[word[i] - 'a'];
        }
        // 匹配到了一个子串，看看这个子串是不是结束了，如果结束了那就说明匹配到了，否则就是没匹配到~
        return node->is_end;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie *node = root;
        for (char c : word) {
            if (node->next[c - 'a'] == nullptr) node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return subSearch(root, word);
    }
};