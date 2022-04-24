
/**
 * Created by Xiaozhong on 2022/4/20.
 * Copyright (c) 2022/4/20 Xiaozhong. All rights reserved.
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

class Solution {
    struct Node {
        vector<Node *> children;
        bool isEnd = false;

        Node() : children(vector<Node *>(26, nullptr)) {}
    };

    Node *root;

    void insert(const string &str) {
        Node *node = root;
        for (char c: str) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new Node();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    string search(const string &str) {
        int idx = 0;
        Node *node = root;
        while (idx < static_cast<int>(str.size())) {
            if (node->isEnd) return str.substr(0, idx);
            char c = str[idx];
            if (node->children[c - 'a'] == nullptr) return "";
            node = node->children[c - 'a'];
            idx++;
        }
        return "";
    }

    vector<string> split(const string &str) {
        vector<string> ret;
        string buffer;
        for (char c: str) {
            if (c == ' ') {
                ret.push_back(buffer);
                buffer.clear();
            } else buffer.push_back(c);
        }
        if (!buffer.empty()) ret.push_back(buffer);
        return ret;
    }

public:
    Solution() : root(new Node()) {}

    string replaceWords(vector<string> &dictionary, string sentence) {
        for (const string &item: dictionary) insert(item);
        vector<string> items = split(sentence);
        string ans;
        for (const string &item: items) {
            string ret = search(item);
            if (ret.empty()) ans.append(" ").append(item);
            else ans.append(" ").append(ret);
        }
        return ans.substr(1, ans.size() - 1);
    }
};

int main() {
    vector<string> dictionary = {"cat", "bat", "rat"};
    Solution s;
    cout << s.replaceWords(dictionary, "the cattle was rattled by the battery") << endl;

}











