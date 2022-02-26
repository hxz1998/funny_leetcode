/**
 * Created by Xiaozhong on 2022/2/26.
 * Copyright (c) 2022/2/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Trie {
private:
    struct Node {
        bool isEnd = false;
        vector<Node *> next;

        Node() {
            next = vector<Node *>(26, nullptr);
        }
    };

    Node *root;
public:
    Trie() {
        root = new Node;
    }

    void insert(string word) {
        Node *curr = root;
        for (int idx = 0; idx < word.size(); ++idx) {
            int offset = word[idx] - 'a';
            if (curr->next[offset] == nullptr) {
                Node *node = new Node;
                curr->next[offset] = node;
            }
            curr = curr->next[offset];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        Node *curr = root;
        for (int idx = 0; idx < word.size(); ++idx) {
            int offset = word[idx] - 'a';
            if (curr->next[offset] == nullptr) return false;
            curr = curr->next[offset];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node *curr = root;
        for (int idx = 0; idx < prefix.size(); ++idx) {
            int offset = prefix[idx] - 'a';
            if (curr->next[offset] == nullptr) return false;
            curr = curr->next[offset];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
}