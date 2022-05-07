/*
 * Created by Xiaozhong on 5/6/2022.
 * Copyright (c) 5/6/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
    struct Node {
        bool isEnd;
        vector<Node *> children;

        Node() : isEnd(false), children(vector<Node *>(26, nullptr)) {}
    };

    void insert(const string &word) {
        Node *curr = root;
        for (int idx = static_cast<int>(word.size() - 1); idx >= 0; --idx) {
            char c = word[idx];
            if (curr->children[c - 'a'] == nullptr) curr->children[c - 'a'] = new Node();
            curr->isEnd = false;
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }

    void dfs(Node *curr, int path) {
        if (curr == nullptr) return;
        if (curr->isEnd) ans += path;
        bool isLeaf = true;
        for (Node *next: curr->children) {
            if (next != nullptr) isLeaf = false;
            dfs(next, path + 1);
        }
        if (isLeaf) ans += 1;
    }

public:
    int minimumLengthEncoding(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) {
            return lhs.size() < rhs.size();
        });
        for (const string &word: words) insert(word);
        dfs(root, 0);
        return ans;
    }

private:
    int ans = 0;
    Node *root = new Node();
};

int main(int argc, char **argv) {
    vector<string> words = {"time", "me", "bell"};
    Solution s;
    cout << s.minimumLengthEncoding(words) << endl;
}