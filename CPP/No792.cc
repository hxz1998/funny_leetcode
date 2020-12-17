/**
 * Created by Xiaozhong on 2020/12/16.
 * Copyright (c) 2020/12/16 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Node {
public:
    string word;
    int idx;

    Node(string &w, int i) : word(w), idx(i) {}
};

class Solution {
public:
    int numMatchingSubseq(string S, vector<string> &words) {
        int ans = 0;
        vector<vector<Node>> heads(26);
        for (string &word : words) {
            heads[word.front() - 'a'].emplace_back(word, 0);
        }
        for (char c : S) {
            vector<Node> old_bucket = heads[c - 'a'];
            heads[c - 'a'] = vector<Node>();
            for (Node node : old_bucket) {
                node.idx++;
                if (node.idx == node.word.length()) ans++;
                else heads[node.word[node.idx] - 'a'].emplace_back(node);
            }
            old_bucket.clear();
        }
        return ans;
    }
};