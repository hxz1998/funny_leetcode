/**
 * Created by Xiaozhong on 2022/5/5.
 * Copyright (c) 2022/5/5 Xiaozhong. All rights reserved.
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

class MagicDictionary {
    struct Node {
        bool isEnd = false;
        unordered_map<char, Node *> children;

        Node() {}
    };

public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for (const string &word: dictionary) insert(word);
    }

    bool search(string searchWord) {
        bool used = false;
        return dfs(searchWord, 0, root, used);
    }

private:
    bool dfs(const string &word, int pos, Node *curr, bool used) {
        if (pos == word.size()) {
            if (used && curr->isEnd) return true;
            else return false;
        }
        if (curr->children.empty())
            return false;
        for (const pair<char, Node *> next: curr->children) {
            if (next.first == word[pos]) {
                if (dfs(word, pos + 1, next.second, used)) return true;
            } else {
                if (!used && dfs(word, pos + 1, next.second, true)) return true;
            }
        }
        return false;
    }

    void insert(const string &word) {
        Node *curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) curr->children[c] = new Node();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }

private:
    Node *root = new Node();
};

int main() {
    vector<string> words = {"hello", "leetcode"};
    MagicDictionary magicDictionary;
    magicDictionary.buildDict(words);
    cout << boolalpha << magicDictionary.search("hlllo");
}