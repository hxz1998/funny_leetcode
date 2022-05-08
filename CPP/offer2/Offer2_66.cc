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

class MapSum {
    struct Node {
        int val;
        vector<Node *> children;

        Node() : val(0), children(26, nullptr) {}
    };

public:
    MapSum() {

    }

    void insert(string key, int val) {
        int delta = val;
        if (cnt.find(key) != cnt.end()) delta -= cnt[key];
        cnt[key] = val;
        Node *curr = root;
        for (const char &c: key) {
            if (curr->children[c - 'a'] == nullptr) curr->children[c - 'a'] = new Node();
            curr = curr->children[c - 'a'];
            curr->val += delta;
        }
    }

    int sum(string prefix) {
        Node *curr = root;
        for (const char &c: prefix) {
            if (curr->children[c - 'a'] == nullptr) return 0;
            curr = curr->children[c - 'a'];
        }
        return curr->val;
    }

private:
    Node *root = new Node();
    unordered_map<string, int> cnt;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */