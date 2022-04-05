/**
 * Created by Xiaozhong on 2020/11/24.
 * Copyright (c) 2020/11/24 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    string longestWord(vector<string> &words) {
//        string ans;
//        unordered_set<string> wordSet;
//        for (auto &word : words) wordSet.insert(word);
//        for (auto &word : words) {
//            if (word.length() > ans.length() || word.length() == ans.length() && word < ans) {
//                bool good = true;
//                for (int k = 1; k < word.length(); ++k) {
//                    if (!wordSet.count(word.substr(0, k))) {
//                        good = false;
//                        break;
//                    }
//                }
//                if (good) ans = word;
//            }
//        }
//        return ans;
//    }
//};

class Solution {
private:
    struct Node {
        bool isEnd = false;
        vector<Node *> next;

        Node(bool end = false) : isEnd(end) {
            next = vector<Node *>(26, nullptr);
        }
    };

    Node *root = new Node(true);
public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) {
            return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
        });
        string ans;
        for (const string &word: words) {
            Node *node = root;
            bool flag = true;
            int length = 0;
            for (int i = 0; i < static_cast<int>(word.size()); ++i) {
                char c = word[i];
                int idx = c - 'a';
                if (node->isEnd == false) flag = false;
                if (node->next[idx] == nullptr) {
                    node->next[idx] = new Node;
                    if (i != word.size() - 1) flag = false;
                }
                length++;
                node = node->next[idx];
            }
            node->isEnd = true;
            if (flag && length > ans.size()) ans = word;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    words = {"t", "ti", "tig", "tige", "tiger", "e", "en", "eng", "engl", "engli", "englis", "english", "h", "hi",
             "his", "hist", "histo", "histor", "history"};
    words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << s.longestWord(words) << endl;
}