/**
 * Created by Xiaozhong on 2022/3/17.
 * Copyright (c) 2022/3/17 Xiaozhong. All rights reserved.
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

using namespace std;

class Solution {
private:
    bool connected(const string &lhs, const string &rhs) {
        bool founded = false;
        for (int idx = 0; idx < lhs.size(); ++idx) {
            if (lhs[idx] != rhs[idx]) {
                if (!founded) founded = true;
                else return false;
            }
        }
        return true;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_map<string, vector<string>> graph;
        bool founded = false;
        for (const string &from: wordList) {
            if (connected(beginWord, from)) graph[beginWord].emplace_back(from);
            if (connected(from, endWord)) graph[from].emplace_back(endWord);
            if (from == endWord) founded = true;
            for (const string &to: wordList) {
                if (to == endWord) continue;
                if (to != from && connected(from, to)) graph[from].emplace_back(to);
            }
        }
        if (graph[beginWord].empty() || !founded) return 0;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int ans = 1;
        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            for (int i = 0; i < sz; ++i) {
                string from = q.front();
                q.pop();
                for (const string &to: graph[from]) {
                    if (visited.find(to) != visited.end()) continue;
                    visited.insert(to);
                    if (to == endWord) return ans + 1;
                    q.push(to);
                }
            }
            ans++;
        }
        return 0;
    }
};

int main() {
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    cout << s.ladderLength("hit", "cog", words) << endl;
}