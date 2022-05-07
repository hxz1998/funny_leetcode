/**
 * Created by Xiaozhong on 2022/4/26.
 * Copyright (c) 2022/4/26 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Trie {
private:
    struct Node {
        bool isEnd = false;
        vector<Node *> children;

        Node() {
            children = vector<Node *>(26, nullptr);
        }
    };

    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() : root(new Node()) {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
        for (char c: word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) curr->children[index] = new Node();
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for (char c: word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return curr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *curr = root;
        for (char c: prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    unordered_map<int, int> mapper;
//    cout << mapper[2] << endl;
    cout << mapper.count(2) << endl;
    cout << mapper.count(2) << endl;
    mapper.find(2);
    mapper[0] = 1;
}